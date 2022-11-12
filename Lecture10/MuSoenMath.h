#include <iostream>
#pragma once
class mat3 {
public:
	float matrix[3][3];
	mat3();
	mat3(float mat00, float mat01, float mat02
			, float mat10, float mat11, float mat12
			, float mat20, float mat21, float mat22) {
			matrix[0][0] = mat00; matrix[0][1] = mat01; matrix[0][2] = mat02;
			matrix[1][0] = mat10; matrix[1][1] = mat11; matrix[1][2] = mat12;
			matrix[2][0] = mat20; matrix[2][1] = mat21; matrix[2][2] = mat22;
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

	mat3 operator*(mat3& mat) {
		return multiply_matrix(mat);
	}
	mat3 multiply_matrix(mat3& mat) {
		mat3 result;
		int x = 0, y = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				result.matrix[y][x] = matrix[i][j] * mat.matrix[j][i];
				x++; if (x > 2) { x = 0; y++; }
			}
		}
		return result;
	}
	
	mat3 operator+(mat3& mat) {
		return add_matrix(mat);
	}
	mat3 add_matrix(mat3& mat) {
		mat3 result;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				result.matrix[i][j] = matrix[i][j] + mat.matrix[i][j];
			}
		}
		return result;
	}

	mat3 operator-(mat3& mat) {
		return subtrack_matrix(mat);
	}
	mat3 subtrack_matrix(mat3& mat) {
		mat3 result;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				result.matrix[i][j] = matrix[i][j] - mat.matrix[i][j];
			}
		}
		return result;
	}

	mat3 operator*(float constant) {
		const_multiply_matrix(constant);
	}
	mat3 const_multiply_matrix(float constant) {
		mat3 result;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				result.matrix[i][j] = matrix[i][j] * constant;
			}
		}
		return result;
	}

	mat3 operator/(float constant) {
		const_devide_matrix(constant);
	}
	mat3 const_devide_matrix(float constant) {
		mat3 result;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				result.matrix[i][j] = matrix[i][j] / constant;
			}
		}
		return result;
	}

	//b) multiply transpose matrix  ???
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
	void print() {
		std::cout << "x : " << x << ",y : " << y << ",z : " << z << "\n";
	}
	vec3 operator*(mat3& mat) {
		return calculate(mat);
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

	vec3 operator*(vec3& vec) {
		multiply_vec3(vec);
	}
	vec3 multiply_vec3(vec3& vec) {
		vec3 result;

		result.x = x * vec.x;
		result.y = y * vec.y;
		result.y = z * vec.z;

		return result;
	}

	vec3 operator+(vec3& vec) {
		return add_vec3(vec);
	}
	vec3 add_vec3(vec3& vec) {
		vec3 result;
		result.x = x + vec.x;
		result.y = y + vec.y;
		result.z = z + vec.z;
		return result;
	}

	vec3 operator-(vec3& vec) {
		return	subtrack_vec3(vec);
	}
	vec3 subtrack_vec3(vec3& vec) {
		vec3 result;
		result.x = x - vec.x;
		result.y = y - vec.y;
		result.z = z - vec.z;
		return result;
	}

	vec3 operator*(float constant) {
		return const_multiply_vec3(constant);
	}
	vec3 const_multiply_vec3(float constant) {
		vec3 result;
		result.x = x * constant;
		result.y = y * constant;
		result.z = z * constant;
		return result;
	}

	vec3 operator/(float constant) {
		return const_devide_vec3(constant);
	}
	vec3 const_devide_vec3(float constant) {
		vec3 result;
		result.x = x / constant;
		result.y = y / constant;
		result.z = z / constant;
		return result;
	}
};
	//d) multiply transpose vector ???
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
