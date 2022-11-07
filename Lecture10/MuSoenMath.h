#include <iostream>
#pragma once
class mat3 {
public:
	float matrix[3][3];
	mat3(){}
	mat3(float mat00, float mat01, float mat02
		, float mat10, float mat11, float mat12
		, float mat20, float mat21, float mat22) {
		matrix[0][0] = mat00; matrix[0][1] = mat01; matrix[0][2] = mat02;
		matrix[1][0] = mat10; matrix[1][1] = mat11; matrix[1][2] = mat12;
		matrix[2][0] = mat20; matrix[2][1] = mat21; matrix[2][2] = mat22;
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
			std::cout << "x : " << x << ",y : " << y << ",z : " << z<<"\n";
		}
		vec3 operator*(mat3 &mat) {
			vec3 result;
			result.x = (mat.matrix[0][0] * x) + (mat.matrix[0][1] * y) + (mat.matrix[0][2] * z);
			result.y = (mat.matrix[1][0] * x) + (mat.matrix[1][1] * y) + (mat.matrix[1][2] * z);
			result.z = (mat.matrix[2][0] * x) + (mat.matrix[2][1] * y) + (mat.matrix[2][2] * z);
			return result;
		}
		vec3 calculate(mat3& mat) {
			vec3 result;
			result.x = (mat.matrix[0][0] * x) + (mat.matrix[0][1] * y) + (mat.matrix[0][2] * z);
			result.y = (mat.matrix[1][0] * x) + (mat.matrix[1][1] * y) + (mat.matrix[1][2] * z);
			result.z = (mat.matrix[2][0] * x) + (mat.matrix[2][1] * y) + (mat.matrix[2][2] * z);
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
