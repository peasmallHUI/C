/*填充下面的代码，以实现题目中的着色方程（不可改动其他部分）：*/
#include <cmath>    // std::pow(a, b)
#include <iostream>
#include <iomanip>

using namespace std;

struct float3 {
	float3() {}
	float3(float x, float y, float z) : x(x), y(y), z(z) {}
	~float3() {}

	float3 operator+(const float3& rhs) const {
		// 填充：实现矢量加法
		return float3(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
	}

	float3 operator-(const float3& rhs) const {
		// 填充：实现矢量减法
		return float3(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
	}

	float3 operator*(float rhs) const {
		// 填充：实现矢量与纯量的乘法
		return float3(this->x * rhs, this->y * rhs, this->z * rhs);
	}

	float3 operator*(const float3& rhs) const {
		// 填充：实现矢量与矢量的逐分量乘法
		return float3(this->x * rhs.x, this->y * rhs.y, this->z * rhs.z);
	}

	float3& operator+=(const float3& rhs) {
		return *this = *this + rhs;
	}

	friend ostream& operator<<(ostream& os, const float3& v) {
		return os << fixed << setprecision(3) << v.x << " " << v.y << " " << v.z;
	}

	friend istream& operator>>(istream& is, float3& v) {
		return is >> v.x >> v.y >> v.z;
	}

	float x, y, z;
};

float3 normalize(const float3& v) {
	// 填充：实现矢量归一化
	float mang = pow(v.x*v.x + v.y*v.y + v.z*v.z, 0.5);
	return float3(v.x / mang, v.y / mang, v.z / mang);
}

float max(float a, float b) {
	// 填充：求两数的最大值
	return (a > b ? a : b);
}

float dot(const float3& a, const float3& b) {
	// 填充：求两矢量的点积
	return (a.x*b.x + a.y*b.y + a.z*b.z);
}

float3 Shade(
	const float3& p,
	const float3& n,
	const float3& pv,
	const float3& Kd,
	const float3& Ks,
	float m,
	unsigned lightCount,
	const float3* l,
	const float3* EL)
{
	// 填充：实现着色方程
	float3 Lo(0, 0, 0);
	float3 v = normalize(pv - p);
	for (int i = 0; i < lightCount; i++)
	{
		float3 hk = normalize(v + *(l + i));
		float cos_hk = max(0, dot(hk, n));
		float cos_ik = max(0, dot(n, normalize(*(l + i))));
		Lo += ((Kd + Ks * pow(cos_hk, m)) * ((*(EL + i))*cos_ik));
	}
	return Lo;
}

int main() {
	float3 p;
	float3 n;
	float3 pv;
	float3 Kd;
	float3 Ks;
	float m;
	unsigned lightCount;
	cin >> p >> n >> pv >> Kd >> Ks >> m >> lightCount;

	float3* l = new float3[lightCount];
	float3* EL = new float3[lightCount];
	for (unsigned k = 0; k < lightCount; k++)
		cin >> l[k] >> EL[k];

	cout << Shade(p, n, pv, Kd, Ks, m, lightCount, l, EL) << endl;

	delete[] l;
	delete[] EL;
}