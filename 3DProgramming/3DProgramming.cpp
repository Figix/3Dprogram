#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#pragma comment(lib, "OpenGL32")

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

}

void colorTrans(int angle);

int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 640, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;

        ////90도와 같이 각도로 연산하고 싶으면
        ////glm의 삼각함수는 radian 형식으로 입력을 받기 때문에 변환해서 넣어주어야한다.
        //glm::sin(glm::radians(90.0));  
        
        glClearColor(.0f, 0.0f, 0.0f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);

        glLineWidth(20);
        glBegin(GL_LINE_STRIP);
        // 호도법의 각 = 육식분법의 각 * pi / 180
        double radius = 1;
        for (int i = 0; i < 360; i++) {
            double theta = i * 3.141592 / 180;
            double x = radius * cos(theta);
            double y = radius * sin(theta);
            colorTrans(i);
            glVertex3f(x, y, 0.0f);
        }
        

        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    
    exit(EXIT_SUCCESS);
}

void colorTrans(int angle) {
    angle = angle % 180;
    switch (angle / 25) {
        case 0:     //빨강
            glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
            break;
        case 1:     //주황
            glColor4f(1.0f, 0.2f, 0.0f, 1.0f);
            break;
        case 2:     //노랑
            glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
            break;
        case 3:     //초록
            glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
            break;
        case 4:     //파랑
            glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
            break;
        case 5:     //남색
            glColor4f(0.0f, 0.02f, 1.0f, 1.0f);
            break;
        default:    //보라 6,7이 몫으로 나오는데 둘다 보라로 만듬
            glColor4f(0.4f, 0.0f, 1.0f, 1.0f);
            break;
    }
}