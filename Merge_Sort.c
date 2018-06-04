#include<stdio.h>
#include<stdlib.h>

int merge(int A[],int l,int m,int r,long *x)
{
    
    int n = r-l+1;
    int n1 = m-l+1;
    int n2 = r-m;
    int i = 0;
    int j = 0;
    int k = l;
    int B[n1],C[n2];
    for(int y = 0; y<n1; y++)
    {
        B[y] = A[l+y];
        //printf("B[%d] = %d  ",x,B[x]);
    }   
    
    for(int y=0; y<n2; y++)
    {
        C[y] = A[m+1+y];
        //printf("C[%d] = %d  ",x,C[x]);        
    } 
    
    while(i<n1 && j<n2)
    {
        
            if(B[i]<C[j])
            {
                A[k]=B[i];
                i++;
                k++;
                //(*x)++;
            }
            else if(B[i]>C[j])
            {
                A[k]=C[j];
                j++;
                k++;
                int z = n1-i;
                //printf("Inversion detected\n");
                //printf("i is %d and n1 is %d\n",i,n1);
                //printf("x was %d\n",(*x));
                (*x) = (*x) + z ;
                /*if((*x)<=0)
                {
                    
                    printf("B[i] = %d and C[j] = %d\n",B[i],C[j]);
                    exit(1);
                 }*/
                //printf("x is %li\n",(*x));
            }   
        
    }
    if(i>=n1)
    {
        do{
            A[k] = C[j];
            j++;
            k++;
            //(*x)++;
        }while(k<=r);
    }
    else if(j>=n2)
    {
        do{
            A[k] = B[i];
            i++;
            k++;
            //(*x)++;
        }while(k<=r);
    }
    /*printf("This is result after merge.\n");
    
    for(int i = l; i<= r; i++)
    {
        printf("A[%d] = %d  ",i,A[i]);              
    }
    printf("\n");
    */
}


void sort(int A[], int l,int r,long *x)
{   
    
    if(l<r)
    {
        int m = (l + r)/2;
        sort(A,l,m,x);
        sort(A,m+1,r,x);
        merge(A,l,m,r,x);  
       
    }
    
}



void display(int A[],int n)
{
    for(int i = 0; i< n; i++)
    {
        printf("A[%d] = %d  ",i,A[i]);
        
    }
    printf("\n");
}
      
void inc(int A[],int n,int *x)
{   
    //*x=5;
    for(int i = 0; i< n; i++)
     {   A[i] = A[i] +1;
         //(*x)++;
      }  
    display(A,n);
}         

int main(int argc,char *argv[])
{
    int n = 100000;
    //int A[] = {7,6,4,8,3,5,2,9};
    int B[100000]={0};
    //int n = sizeof(A)/sizeof(A[0]);
    long x =0;
    FILE *fp;
    fp = fopen("IntegerArray.txt","r");
    for(int i = 0; i<n; i++)
    {
        fscanf(fp,"%d",&B[i]);                    
    }
    fclose(fp);
    
    //display(A,n);
    //display(B,n);
    
    sort(B,0,n-1,&x);
    display(B,n);
    printf("the number of inversions are : %li\n",x);
    
    return 0;
}













