#include<stdio.h>
#include<stdlib.h>

struct library
{
  int Bno;
  char Bname[15];
  int Bprize;
  char Bautor[20];
  char Bcolour[10];
  int  Bshelf;
} b;


int main ()
{
  FILE *fp, *fp1;
  int n, i, a, choice,r;
  char ch;
  while (1)
   {
      printf ("\t 1.INSERT 2.DISPLAY 3.SEARCH 4.UPDATE 5.DELETE 6.EXIT \t \n");
      scanf ("%d", &choice);
      switch (choice)
        {
        case 1:
          fp = fopen ("data.txt", "ab");
          printf ("HOW MANY BOOKS DETAILS\n");
          scanf ("%d", &n);
          for (i = 0; i < n; i++)
            {
              printf ("Enter BOOK NUMBER,BOOK NAME,BOOK PRIZE,AUTHOR NAME,BOOK COLOUR , SHELLF NUMBER\n");
              scanf ("%d%s%d%s%s%d", &b.Bno, b.Bname,&b.Bprize,b.Bautor,b.Bcolour,&b.Bshelf);
           
              fwrite (&b, sizeof (b), 1, fp);
          }
          fclose (fp);
        break;
 case 2:
          fp = fopen ("data.txt", "rb");

          printf("\nBOOK no\tBOOK Name\tprize\tBOOK author\tBOOK colour\tBOOK shelf\n");
          while (fread (&b, sizeof (b), 1, fp) == 1)
            {
              printf ("BOOK DETAILS.....\n", i + 1);
              printf ("BOOK NUMBER: %d\n", b.Bno);
              printf ("BOOK NAME: %s\n", b.Bname);
              printf ("BOOK PRIZE: %d\n",b.Bprize);
              printf ("BOOK AUTHOR: %s\n", b.Bautor);
              printf ("BOOK COLOUR: %s\n", b.Bcolour);
              printf ("BOOK SHELF: %d\n",b.Bshelf);
         }
          break;
        case 3:
          printf("Enter the BOOK ID to print the details of the BOOK\n");
          while (scanf("%d", &b.Bno) != 1) {
          printf("Invalid input. Please enter a valid BOOK ID.\n");
          while (getchar() != '\n');
          }
          fseek(fp, (b.Bno - 1) * sizeof(b), 0);
          if (fread(&b, sizeof(b), 1, fp) != 1)
             {
            printf("Not found data.\n");
              }
              else
              { 
              printf ("BOOK DETAILS.....\n", i + 1);
              printf ("BOOK NUMBER: %d\n", b.Bno);
              printf ("BOOK NAME: %s\n", b.Bname);
              printf ("BOOK PRIZE: %d\n",b.Bprize);
              printf ("BOOK AUTHOR: %s\n", b.Bautor);
              printf ("BOOK COLOUR: %s\n", b.Bcolour);
              printf ("BOOK SHELF: %d\n",b.Bshelf);
          fclose (fp);
          fp =fopen("data.txt","rb");
          }
          break;
 case 4:
    fp = fopen ("data.txt", "rb+");
    printf ("Enter the book id which record to be modify\n");
    scanf ("%d", &b.Bno);
    printf ("Which data  you want to modify\n");
    do
      {
        printf("1.BOOK ID 2.BOOK NAME 3.BOOK PRIZE 4.BOOK AUTHOR 5.BOOK COLOUR 6.B SHELF \n");
        scanf ("%d", &choice);
        switch (choice)
          {
          case 1:
                fseek(fp, (b.Bno -1) * sizeof(b),0);
            printf ("enter the book id  modify\n");
            scanf ("%d", &b.Bno);
        fwrite (&b, sizeof (b), 1, fp);
            break;
          case 2:
                fseek(fp, (b.Bno -1) * sizeof(b),0);
            printf ("enter the book  name\n");
            scanf ("%s", &b.Bname);
        fwrite (&b, sizeof (b), 1, fp);
            break;
          case 3:
        fseek(fp, (b.Bno -1) * sizeof(b),0);
            printf ("enter the BOOK prize\n");
            scanf ("%d", &b.Bprize);
         fwrite (&b, sizeof (b), 1, fp);
            break;
          case 4:
                fseek(fp, (b.Bno -1) * sizeof(b),0);
            printf ("enter the BOOK AUTHOR \n");
            scanf ("%c", &b.Bautor);
         fwrite (&b, sizeof (b), 1, fp);
            break;
          case 5:
                fseek(fp, (b.Bno -1) * sizeof(b),0);
            printf ("enter the BOOK colour\n");
            scanf ("%s", &b.Bcolour);
        fwrite (&b, sizeof (b), 1, fp);
            break;
          case 6:
                fseek(fp, (b.Bno -1) * sizeof(b),0);
            printf ("enter the book shelf\n");
            scanf ("%s", &b.Bshelf);
                fwrite (&b, sizeof (b), 1, fp);
            break;
        }
         printf("do you want to mofify any other data \n");
              __fpurge (stdin);
        scanf("%c",&ch);
     }
  while(ch=='y');
    fclose (fp);
          fp = fopen ("data.txt", "rb");
        printf ("Record modified\n");
         while (fread (&b, sizeof (b), 1, fp) == 1)
            {
              printf ("\n", i + 1);
              printf ("BOOK NUMBER: %d\n", b.Bno);
              printf ("BOOK NAME: %s\n", b.Bname);
              printf ("BOOK PRIZE: %d\n",b.Bprize);
              printf ("BOOK AUTHOR: %s\n", b.Bautor);
              printf ("BOOK COLOUR: %s\n", b.Bcolour);
              printf ("BOOK SHELF: %d\n",b.Bshelf);

           }
          fclose (fp);
          break;
 case 5:
          fp = fopen ("data.txt", "rb");
          fp1 = fopen ("temp.txt", "wb");
          printf ("Enter the BOOK ID to delet the detils of BOOK..\n");
          scanf ("%d", &a);
          while (fread (&b, sizeof (b), 1, fp) == 1)
            {
              if (b.Bno != a)
                {
                  fseek (fp, (b.Bno - 1) * sizeof (b), 0);
                  {
                    fread (&b, sizeof (b), 1, fp);
                    fwrite (&b, sizeof (b), 1, fp1);
                  }
                }
            }
          fclose (fp);
          fclose (fp1);

          fp = fopen ("data.txt", "wb");
          fp1 = fopen ("temp.txt", "rb");
          while (fread (&b, sizeof (b), 1, fp1) == 1)
            {
//                fseek (fp, (b.Bno - 1) * sizeof (b), 0);
//                {
//                  fread (&b, sizeof (b), 1, fp1);
                    fwrite (&b, sizeof (b), 1, fp);
                  }
           // }
          fclose (fp);
          fclose (fp1);

           fp = fopen("data.txt","rb");
             while (fread (&b, sizeof (b), 1, fp) == 1)
             {
              printf ("\n", i + 1);
              printf ("BOOK NUMBER: %d\n", b.Bno);
              printf ("BOOK NAME: %s\n", b.Bname);
              printf ("BOOK PRIZE: %d\n",b.Bprize);
              printf ("BOOK AUTHOR: %s\n", b.Bautor);
              printf ("BOOK COLOUR: %s\n", b.Bcolour);
              printf ("BOOK SHELF: %d\n",b.Bshelf);


              }
             fclose (fp);

          break;
 case 6:
          exit (1);

        }
    }
}