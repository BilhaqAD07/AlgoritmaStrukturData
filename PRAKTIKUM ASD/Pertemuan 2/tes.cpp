#include <iostream>
using namespace std;

void printMatriks(float matriks[][2]){
    int i=0, j=0;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            cout << matriks[i][j] << "  ";
        }
            cout << endl;
    }
    cout << endl;
}

void inverseMatriks(float *a,float det){
    *a /= det;
}

void inputMatriks(float matriks[][2]){
    int i=0, j=0;
    cout << "Masukkan Nilai : " << endl;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("Matriks [%d][%d] = ", i, j);
            cin >> matriks[i][j];
        }
    }
}

int main()
{
    float matriks[2][2];
    cout << "Masukkan Nilai :" << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Matriks [%d][%d] = ", i, j);
            cin >> matriks[i][j];
        }
    }
    cout << "Matriks Biasa :" << endl;
    printMatriks(matriks);

    cout << "Matriks Invers :" << endl;
    float det = (matriks[0][0] * matriks[1][1]) - (matriks[0][1] * matriks[1][0]);
	float temp = matriks[0][0];
    matriks[0][0]=matriks[1][1];
	matriks[0][1]=-1*matriks[0][1];
	matriks[1][0]=-1*matriks[1][0];
    matriks[1][1]=temp;
	if ( det != 0){
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				inverseMatriks(&matriks[i][j],det);
			}
		}
		printMatriks(matriks);
	}else
        cout << "Tidak memenuhi syarat matriks invers" << endl;
    
    return 0;
}