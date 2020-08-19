#include "question.h"
void PromptTheQuestions ( Question_T *ptr )
{
     while ( ptr != NULL ) {
        // PROMPT EACH AND EVERY QUESTION TO THE USER
        printf ( "%s", ptr->question);
        printf ( "%s", ptr->answer1);
        printf ( "%s", ptr->answer2);
        printf ( "%s", ptr->answer3);
        printf ( "%s", ptr->answer4);

       scanf ( "%d",  &(ptr->userTypedAnswer) );

        ptr = ptr->next ; // KEY POINT IN TRAVERSING LINKED LIST
     }
}

