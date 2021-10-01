#include<stdio.h>
int main()
{
    int i,j,k,n;
    float c;
    printf("\nEnter number of equation: ");
    scanf("%d",&n);
    printf("\n\nInput Matrix: \n");
    float A[n][n+1],x[n];
    for(i=0; i<n; i++)
    {
        for(j=0; j<n+1; j++)
        {
            scanf("%f",&A[i][j]);
        }
    }
    /* Now finding the elements of diagonal matrix */
    for(j=0; j<n; j++)
    {
        for(i=0; i<n; i++)
        {
            if(i!=j)
            {
                c=A[i][j]/A[j][j];
                for(k=0; k<n+1; k++)
                {
                    A[i][k]=A[i][k]-c*A[j][k];
                }
            }
        }
    }

    printf("\n\n\n\nTriangular matrix: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n+1; j++)
        {
            printf("%.2f\t",A[i][j]);
        }
        printf("\n");
    }


    printf("\nThe solution is:\n");
    for(i=0; i<n; i++)
    {
        x[i]=A[i][n]/A[i][i];
        printf("\n x%d=%.2f\n",i,x[i]);
    }
    return 0;
}

