#include <stdio.h>
int main ()
{
  int *p;
  int *q;
  int b[3][3];
  int a[3][3];
  //int i, j, k;
  p = &a[0][0];
  q = &b[0][0];
  int c[3][3];
  int mul[3][3];
  int min, max, s[2][2];
  int choice;
  do
  {
  printf("Avaiable Operations\n");
  printf ("enter your choice\n");
  printf ("1:Addition\n");
  printf ("2.Multiplication\n");
  printf ("3:Saddle point of array\n");
  printf ("4:Exit\n");
  scanf ("%d", &choice);
 
  switch (choice)
    {
      case 1:
      {
      printf ("Addition of the matrix\n");
      printf ("enter an array");
  for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
         {
           scanf ("%d", &a[i][j]);
         }

    }
   
  printf ("enter another array");
  for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
         {
           scanf ("%d", &b[i][j]);
         }

    }
     
      for (int i = 0; i < 3; i++)
        {
           for (int j = 0; j < 3; j++)
              {
                c[i][j] = (*(p + ((i * 3) + j))) + (*(q + ((i * 3) + j)));
              }
              printf ("\n");
        }
      for (int i = 0; i < 3; i++)
         {
           for (int j = 0; j < 3; j++)
              {
                printf ("%d\t", c[i][j]);
              }
           printf ("\n");
         }
      break;
    }

  case 2:
  {
  printf ("multiplication of the matrix=\n");
  printf ("enter an array");
  for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
         {
           scanf ("%d", &a[i][j]);
         }

    }
   
  printf ("enter another array");
  for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
         {
           scanf ("%d", &b[i][j]);
         }

    }
    for (int i = 0; i < 3; i++)
         {
           for (int j = 0; j < 3; j++)
              {
                mul[i][j]=0;

             }
         }
      for (int i = 0; i < 3; i++)
         {
           for (int j = 0; j < 3; j++)
              {
                mul[0][0] = 0;
                for (int k = 0; k < 3; k++)
                   {
                     mul[i][j] =
                     mul[i][j] + (*(p + ((i * 3) + k))) * (*(q + ((k * 3) + j)));
                   }
                               
              }
         }
      //for printing result    
      for (int i = 0; i < 3; i++)
         {
           for (int j = 0; j < 3; j++)
              {
                printf ("%d\t", mul[i][j]);
              }
              printf ("\n");
         }
    
         break;
  }
         


case 3:
{
    int i,j,k;
printf ("Saddle Point of array\n");

   printf("Enter elements\n: ");
    for (i = 0; i < 3; i++)
    {
      for (j = 0; j < 3; j++)
         {
           scanf ("%d", &a[i][j]);
         }

    }
   
   for (i = 0; i < 3; i++)
 {
   min = *(p+((i*3)+j));
   for (j = 0; j < 3; j++)
     {
       if (min >= *(p+((i*3)+j)))
  {
    min = *(p+((i*3)+j));
    s[0][0] = i;
    s[0][1] = j;
  }
     }
   j = s[0][1];
   max = a[0][j];
   for (k = 0; k < 3; k++)
     {
       if (max <= *(p+((k*3)+j)))
  {
    max = *(p+((k*3)+j));
    s[1][0] = k;
    s[1][1] = j;
  }

     }


   if (min == max)
     {
       if (s[0][0] == s[1][0] && s[0][1] == s[1][1])
  {
    printf ("The saddle point is %d", a[s[0][0]][s[0][1]]);
  }
     }
   
 }
 break;
}
 }
 }
      while(choice!=4);
     
      return 0;
    }

