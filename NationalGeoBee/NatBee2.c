#include <string.h>
#include <stdlib.h> // For exit()
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <unistd.h>


struct   _question   {

    char question [ 300 ] ;

     char choice1 [ 200 ] ;

     char choice2 [ 200 ] ;

     char choice3 [ 200 ] ;

     char choice4 [ 200 ] ;

     int correctAnswer ;
     
     int userTypedAnswer ;
  

    struct   _question   *next;

}  ;

struct _question  *QuestionListPtr ;




_question *  CreateNode ( _question node )
{
       _question *ptr = ( _question * ) malloc ( sizeof ( _question ) ) ;

      if ( ptr != NULL ) {
         *ptr = node ;
         ptr->next = NULL ;
         return ptr;
      }
     return NULL;


}

  _question getRandQ (  )
{

 _question quiz ;
 FILE *fp ;

 fp = fopen ( "testQuestions.txt" , "r");

 if ( fp == NULL ) {
    perror ("Something is terribly wrong ");
    exit ( 1 );
 }

 char line[300];
 int questNum, i = 0 ;

 questNum= rand( ) % 50 + 1 ;

 int skipLines = (questNum-1) * 6;

    while ( i < skipLines )  
	{
       fgets ( line, 300, fp );
       i++;
    }


       fgets ( line, 300, fp );
      
       strcpy(quiz.question, line);
       fgets ( line, 300, fp );
       strcpy(quiz.choice1, line);
       
       fgets ( line, 300, fp );
       strcpy(quiz.choice2, line);
       
       fgets ( line, 300, fp );
       strcpy(quiz.choice3, line);
      
       fgets ( line, 300, fp );
       strcpy(quiz.choice4, line);
       
       fgets ( line, 300, fp );
       sscanf ( line, "%d", &quiz.correctAnswer);
       

   fclose ( fp);
   return quiz;
}


void NewNode ( _question *nptr, _question quiz )
{
   _question *temp = CreateNode ( quiz );  

   while ( nptr->next != NULL )  
     nptr = nptr->next ;

    nptr->next = temp ;  

}


void PromptQ ( _question *ptr )
{
	 
	 while ( ptr != NULL ) 
	 
	 {
       
        printf ( "%s", ptr->question);
        printf ( "%s", ptr->choice1);
        printf ( "%s", ptr->choice2);
        printf ( "%s", ptr->choice3);
        printf ( "%s", ptr->choice4);

       scanf ( "%d",  &(ptr->userTypedAnswer) );

        ptr = ptr->next ; 
     }
}


void review ( _question *ptr )
{
	
	 int score =0;
	  
     while ( ptr != NULL )
	  {
      
        printf ( "%s", ptr->question);
        printf ( "%s", ptr->choice1);
        printf ( "%s", ptr->choice2);
        printf ( "%s", ptr->choice3);
        printf ( "%s", ptr->choice4);
        printf ( "%d\n", ptr->correctAnswer);
        printf ("You Answered as %d \n", ptr->userTypedAnswer);
        
       
        ptr = ptr->next ; 
     }

}



 int score(_question *ptr )
{
	 int score =0;
	
	   
        if (ptr->correctAnswer = ptr->userTypedAnswer)
        {
        	score++; 
        	printf(" Your score is %d", score);
		}
		else 
		printf("wrong");
     

   return score; 
}

	
	
	



int main ( )
{
 srand ( time ( NULL )  );

   int i = 0;
   _question *currPtr = NULL , *backUpPtr = NULL  ;
   currPtr = backUpPtr = NULL ;

   _question quiz  = getRandQ ( ) ;
   backUpPtr = currPtr = CreateNode ( quiz );

  

   while ( i < 9 ) {

      _question quiz  = getRandQ ( ) ;
      NewNode (currPtr, quiz);

    i++ ;
   }


  currPtr = backUpPtr;  
  PromptQ ( currPtr) ; 

  currPtr = backUpPtr; 
  review ( currPtr) ;
  score(currPtr);
  
   
  
  
char mailAddress [32] = "taylerjbean@gmail.com";
char body[200] = "Your score in the National Geographic bee is 8/10 ";


execlp ( "./mymail.sh", "./mymail.sh", body, mailAddress, NULL );

}

