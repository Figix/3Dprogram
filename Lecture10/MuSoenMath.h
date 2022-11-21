#include <iostream>
#pragma once
#pragma once
#define PI 3.141592

float radians(float theta) {
	return theta / 180 * PI;
}

class mat3 {
public:
	float matrix[3][3];
	mat3(){
		matrix[0][0] = 0; matrix[0][1] = 0; matrix[0][2] = 0;
		matrix[1][0] = 0; matrix[1][1] = 0; matrix[1][2] = 0;
		matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 0;
	};
	mat3(float mat00, float mat01, float mat02
		, float mat10, float mat11, float mat12
		, float mat20, float mat21, float mat22) {
		matrix[0][0] = mat00; matrix[0][1] = mat01; matrix[0][2] = mat02;
		matrix[1][0] = mat10; matrix[1][1] = mat11; matrix[1][2] = mat12;
		matrix[2][0] = mat20; matrix[2][1] = mat21; matrix[2][2] = mat22;
	}
	void identity_matrix() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j) {
					matrix[i][j] = 1;
				}
				else {
					matrix[i][j] = 0;
				}
			}
		}
	}
	void transpose_matrix() {
		float temp;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i < j) {
					temp = matrix[i][j];
					matrix[i][j] = matrix[j][i];
					matrix[j][i] = temp;
				}
			}
		}
	}
	mat3 operator*(mat3& mat);
	mat3 operator+(mat3& mat);
	mat3 operator-(mat3& mat);
	mat3 operator*(float constant);
	mat3 operator/(float constant);
};
class mat4 {
public:
	float matrix[4][4];
	mat4() {}
	mat4(float mat00, float mat01, float mat02, float mat03
		, float mat10, float mat11, float mat12, float mat13
		, float mat20, float mat21, float mat22, float mat23
		, float mat30, float mat31, float mat32, float mat33) {
		matrix[0][0] = mat00; matrix[0][1] = mat01; matrix[0][2] = mat02; matrix[0][3] = mat03;
		matrix[1][0] = mat10; matrix[1][1] = mat11; matrix[1][2] = mat12; matrix[1][3] = mat13;
		matrix[2][0] = mat20; matrix[2][1] = mat21; matrix[2][2] = mat22; matrix[2][3] = mat23;
		matrix[3][0] = mat20; matrix[3][1] = mat21; matrix[3][2] = mat22; matrix[3][3] = mat33;
	}
	void identity_matrix() {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (i == j) {
					matrix[i][j] = 1;
				}
				else {
					matrix[i][j] = 0;
				}
			}
		}
	}
	void transpose_matrix() {
		float temp;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (i < j) {
					temp = matrix[i][j];
					matrix[i][j] = matrix[j][i];
					matrix[j][i] = temp;
				}
			}
		}
	}

	mat4 operator*(mat4& mat);
	mat4 operator+(mat4& mat);
	mat4 operator-(mat4& mat);

	mat4 operator*(float constant);
	mat4 operator/(float constant);
};

class vec3 {
public:
	float x;
	float y;
	float z;
	vec3() {

	}
	vec3(float x_, float y_, float z_) {
		x = x_;
		y = y_;
		z = z_;
	}
	/*º¤ÅÍ*Çà·Ä*/
	vec3 operator*(mat3& mat);

	/*º¤ÅÍ³¢¸®ÀÇ °ö¼À*/
	vec3 operator*(vec3& vec);
	/*º¤ÅÍ °£ µ¡¼À »¬¼À*/
	vec3 operator+(vec3& vec);
	vec3 operator-(vec3& vec);
	/*º¤ÅÍ¿Í »ó¼ö °ö¼À ³ª´°¼À*/
	vec3 operator*(float constant);
	vec3 operator/(float constant);
};

class vec4 {
public:
	float x;
	float y;
	float z;
	float w;
	vec4() {

	}
	vec4(float x_, float y_, float z_, float w_) {
		x = x_;
		y = y_;
		z = z_;
		w = w_;
	}
	/*º¤ÅÍ*Çà·Ä*/
	vec4 operator*(mat4& mat);

	/*º¤ÅÍ³¢¸®ÀÇ °ö¼À*/
	vec4 operator*(vec4& vec);
	/*º¤ÅÍ °£ µ¡¼À »¬¼À*/
	vec4 operator+(vec4& vec);
	vec4 operator-(vec4& vec);
	/*º¤ÅÍ¿Í »ó¼ö °ö¼À ³ª´°¼À*/
	vec4 operator*(float constant);
	vec4 operator/(float constant);
};
#pragma region mat3
mat3 mat3:: operator*(mat3& mat) {
	mat3 result;
	float tmp = 0.0f;
	for (int i = 0; i < 3; i++) {
		for (int q = 0; q < 3; q++) {
			for (int j = 0; j < 3; j++) {
				tmp += matrix[i][j] * mat.matrix[j][q];
			}
			result.matrix[i][q] = tmp;
		}
	}
	return result;
}
mat3 mat3:: operator+(mat3& mat) {
	mat3 result;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			result.matrix[i][j] = matrix[i][j] + mat.matrix[i][j];
		}
	}
	return result;
}
mat3 mat3:: operator-(mat3& mat) {
	mat3 result;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			result.matrix[i][j] = matrix[i][j] - mat.matrix[i][j];
		}
	}
	return result;
}
mat3 mat3:: operator*(float constant) {
	mat3 result;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			result.matrix[i][j] = matrix[i][j] * constant;
		}
	}
	return result;
}
mat3 mat3:: operator/(float constant) {
	mat3 result;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			result.matrix[i][j] = matrix[i][j] / constant;
		}
	}
	return result;
}
#pragma endregion
#pragma region mat4
mat4 mat4:: operator*(mat4& mat) {
	mat4 result;
	float tmp = 0.0f;
	for (int i = 0; i < 4; i++) {
		for (int q = 0; q < 4; q++) {
			for (int j = 0; j < 4; j++) {
				tmp += matrix[i][j] * mat.matrix[j][q];
			}
			result.matrix[i][q] = tmp;
		}
	}
	return result;
}
mat4 mat4:: operator+(mat4& mat) {
	mat4 result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.matrix[i][j] = matrix[i][j] + mat.matrix[i][j];
		}
	}
	return result;
}
mat4 mat4:: operator-(mat4& mat) {
	mat4 result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.matrix[i][j] = matrix[i][j] - mat.matrix[i][j];
		}
	}
	return result;
}
mat4 mat4:: operator*(float constant) {
	mat4 result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.matrix[i][j] = matrix[i][j] * constant;
		}
	}
	return result;
}
mat4 mat4:: operator/(float constant) {
	mat4 result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.matrix[i][j] = matrix[i][j] / constant;
		}
	}
	return result;
}
#pragma endregion
#pragma region vec3
vec3 vec3:: operator*(mat3& mat) {
	vec3 result;
	result.x = x * mat.matrix[0][0] + y * mat.matrix[1][0] + z * mat.matrix[2][0];
	result.y = x * mat.matrix[0][1] + y * mat.matrix[1][1] + z * mat.matrix[2][1];
	result.z = x * mat.matrix[0][2] + y * mat.matrix[1][2] + z * mat.matrix[2][2];
	return result;
}
vec3 vec3:: operator*(vec3& vec) {
	vec3 result;

	result.x = x * vec.x;
	result.y = y * vec.y;
	result.y = z * vec.z;

	return result;
}
vec3 vec3:: operator+(vec3& vec) {
	vec3 result;
	result.x = x + vec.x;
	result.y = y + vec.y;
	result.z = z + vec.z;
	return result;
}
vec3 vec3:: operator-(vec3& vec) {
	vec3 result;
	result.x = x - vec.x;
	result.y = y - vec.y;
	result.z = z - vec.z;
	return result;
}
vec3 vec3:: operator*(float constant) {
	vec3 result;
	result.x = x * constant;
	result.y = y * constant;
	result.z = z * constant;
	return result;
}
vec3 vec3:: operator/(float constant) {
	vec3 result;
	result.x = x / constant;
	result.y = y / constant;
	result.z = z / constant;
	return result;
}
#pragma endregion
#pragma region vec4
vec4 vec4:: operator*(mat4& mat) {
	vec4 result;
	result.x = x * mat.matrix[0][0] + y * mat.matrix[1][0] + z * mat.matrix[2][0] + w * mat.matrix[3][0];
	result.y = x * mat.matrix[0][1] + y * mat.matrix[1][1] + z * mat.matrix[2][1] + w * mat.matrix[3][1];
	result.z = x * mat.matrix[0][2] + y * mat.matrix[1][2] + z * mat.matrix[2][2] + w * mat.matrix[3][2];
	result.z = x * mat.matrix[0][3] + y * mat.matrix[1][3] + z * mat.matrix[2][3] + w * mat.matrix[3][3];
	return result;
}
vec4 vec4:: operator*(vec4& vec) {
	vec4 result;

	result.x = x * vec.x;
	result.y = y * vec.y;
	result.y = z * vec.z;
	result.w = w * vec.w;

	return result;
}
vec4 vec4:: operator+(vec4& vec) {
	vec4 result;

	result.x = x + vec.x;
	result.y = y + vec.y;
	result.y = z + vec.z;
	result.w = w + vec.w;

	return result;
}
vec4 vec4:: operator-(vec4& vec) {
	vec4 result;

	result.x = x - vec.x;
	result.y = y - vec.y;
	result.y = z - vec.z;
	result.w = w - vec.w;

	return result;
}
vec4 vec4:: operator*(float constant) {
	vec4 result;
	result.x = x * constant;
	result.y = y * constant;
	result.z = z * constant;
	result.w = w * constant;
	return result;
}
vec4 vec4:: operator/(float constant) {
	vec4 result;
	result.x = x / constant;
	result.y = y / constant;
	result.z = z / constant;
	result.w = w / constant;
	return result;
}
#pragma endregion

