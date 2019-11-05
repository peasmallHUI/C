#include <iostream>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int i = 0;
	int* tri = new int[M*3];
	while (i<M)
	{
		cin >> tri[i * 3] >> tri[i * 3 + 1] >> tri[i * 3 + 2];
	}
	for ( i = 0; i < M; i++)
	{
        if (tri[i*3] > tri[i*3+1])
        {
            int temp = tri[i*3];
            tri[i*3] = tri[i*3+1];
            tri[i*3+1] = tri[i*3+2];
            tri[i*3+2] = temp;
        }
        
        if (tri[i*3] > tri[i*3+1])
        {
            int temp = tri[i*3];
            tri[i*3] = tri[i*3+1];
            tri[i*3+1] = tri[i*3+2];
            tri[i*3+2] = temp;
        }
        
	}
	return 0;
}