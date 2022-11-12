#include "MuSoenMath.h"
#include <iostream>


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
	mat4 operator*(mat4& mat) {
		mat4 result;

		return result;
	}
	mat4 operator*(vec4& mat) {
		mat4 result;

		return result;
	}
	void identity_matrix() {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
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
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (i < j) {
					temp = matrix[i][j];
					matrix[i][j] = matrix[j][i];
					matrix[j][i] = temp;
				}
			}
		}
	}
};
class vec3 {
private:
	float x;
	float y;
	float z;
public:
	vec3() {

	}
	vec3(float x_, float y_, float z_) {
		x = x_;
		y = y_;
		z = z_;
	}
	void print() {
		std::cout << "x : " << x << ",y : " << y << ",z : " << z << "\n";
	}
	vec3 operator*(mat3& mat) {
		vec3 result;
		result.x = (mat.matrix[0][0] * x) + (mat.matrix[1][0] * y) + (mat.matrix[2][0] * z);
		result.y = (mat.matrix[1][1] * x) + (mat.matrix[1][1] * y) + (mat.matrix[2][1] * z);
		result.z = (mat.matrix[0][2] * x) + (mat.matrix[1][2] * y) + (mat.matrix[2][2] * z);
		return result;
	}
	vec3 calculate(mat3& mat) {
		vec3 result;
		result.x = (mat.matrix[0][0] * x) + (mat.matrix[1][0] * y) + (mat.matrix[2][0] * z);
		result.y = (mat.matrix[1][1] * x) + (mat.matrix[1][1] * y) + (mat.matrix[2][1] * z);
		result.z = (mat.matrix[0][2] * x) + (mat.matrix[1][2] * y) + (mat.matrix[2][2] * z);
		return result;
	}
	vec3 calculate(vec3& vec, mat3& mat) {
		vec3 result;
		result.x = (mat.matrix[0][0] * vec.x) + (mat.matrix[0][1] * vec.y) + (mat.matrix[0][2] * vec.z);
		result.y = (mat.matrix[1][0] * vec.x) + (mat.matrix[1][1] * vec.y) + (mat.matrix[1][2] * vec.z);
		result.z = (mat.matrix[2][0] * vec.x) + (mat.matrix[2][1] * vec.y) + (mat.matrix[2][2] * vec.z);
		return result;
	}
};
//미완성라인
class vec1x3 {
private:
	float x; float y; float z;
public:
	vec1x3() {}
	vec1x3(float x_, float y_, float z_) { x = x_;  y = y_;  z = z_; }
	void print() { std::cout << "x : " << x << ",y : " << y << ",z : " << z << "\n"; }
	vec1x3 operator*(mat3& mat) {
		vec1x3 result;
		result.x = (mat.matrix[0][0] * x) + (mat.matrix[0][1] * y) + (mat.matrix[0][2] * z);
		result.y = (mat.matrix[1][0] * x) + (mat.matrix[1][1] * y) + (mat.matrix[1][2] * z);
		result.z = (mat.matrix[2][0] * x) + (mat.matrix[2][1] * y) + (mat.matrix[2][2] * z);
		return result;
	}
	vec1x3 calculate(mat3& mat) {
		vec1x3 result;
		result.x = (mat.matrix[0][0] * x) + (mat.matrix[0][1] * y) + (mat.matrix[0][2] * z);
		result.y = (mat.matrix[1][0] * x) + (mat.matrix[1][1] * y) + (mat.matrix[1][2] * z);
		result.z = (mat.matrix[2][0] * x) + (mat.matrix[2][1] * y) + (mat.matrix[2][2] * z);
		return result;
	}
};
class vec4 {

};
class vec1x4 {

};
