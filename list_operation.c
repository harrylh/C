#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

typedef int elemType;

typedef struct {
    elemType element;
    Node *next;
}Node;

elemType gElement;

/* think elemType as int value now   */
int getInput() {
   printf("begin to input one element :\n");
   scanf("%d", &gElement);
   if (gElement < 0) {
      printf("expect an element larger than 0 \n");
      return -1;
   }

   return 0;
}


void printError() {
   printf("errno = %d \n", errno);
   printf("_errno2() = %08x  %s", __errno2(), errnojr);
}

void initList(Node **pNode) {
    *pNode = NULL;
    printf("initList successfullly ...\n");
}
/*create a list                                   */
/* keep adding element until input is less than 0 */
/* see getInput() for more info                   */
/* return List header address                     */
Node *createList() {
    int rc = 0;
    Node *p1 = NULL;
    Node *p2 = NULL;
    Node *pHead = NULL;

    while (getInput() == 0) {
      
      p1 = (Node *)malloc(sizeof(Node));
      if (p1 == NULL) {
         printError();
         return __LINE__;
      }

      memset(p1, 0, sizeof(Node));
      p1->element = gElement;

      if (pHead == NULL) {
         pHead = p1;
      } else {
         p2->next = p1;
      }

      p2 = p1;

    }

    return pHead;

}

/* print List */

void pirntList(Node *pHead) {

   if (pHead == NULL) {
      printf("pHead is NULL \n");
   }
   printf("Begin to print List: \n");

   while (pHead != NULL) {
   
      printf("%d ", pHead->element);
      pHead = pHead->next;
   }
   
}

/* clear the whole List */

void clearList(Node *pHead) {
   Node *pNext = NULL;

   while (pHead != NULL) {
      pNext = pHead->next;
      free(pHead);
      pHead = pNext;
   } 
   
   printf("clear List done... \n");

}

/* sizeof List */

int sizeofList(Node *pHead) {

   int size = 0;

   if (pHead == NULL) {
      printf("pHead is NULL size of pHead is 0 \n");
      return 0;
   }

   while (pHead != NULL) {
      ++size;
      pHead = pHead->next;
   }

   printf("List size is %d \n",size);
   return size;

}

/* delete 1 element from List when it appears on the first time */
Node * delListElem(Node *pHead, elemType element) {

   Node *pDel = NULL;
   Node *pTemp = pHead; /* store header of List */

   int place = 1;  /* record place of this element */

   if (pTemp == NULL) {
      printf("pHead is NULL, input List header !\n");
      return NULL;
   }

   if (pTemp->element == element) {
      pHead = pTemp->next;
      free(pTemp);
      printf("Find it at %d place of List and delete it successfully \n", place);
      return pHead;
   }

   while (pTemp->next != NULL) {
      place++; 
      if (pTemp->next->element == element) {
          pDel = pTemp->next;
          pTemp->next = pDel->next;
          free(pDel);
          printf("Find it at %d place of List and delete it successfully \n", place);
          return pHead;      
      }
      pTemp = Ptemp->next;
   }

   printf("There is no this element in the List\n ");
   printf("We have searched %d elements of the List \n", place);
   return NULL;

}

/* get an element at pos of pHead and output it at pElem  */
int getElem(Node *pHead, int pos, elemType *pElem) {
   int place = 1;
   if (pHead == NULL) {
      printf("pHead is NULL, input valid list header! \n");
      return __LINE__;
   }

   if (pos < 1 || pos > sizeofList(pHead)) {
      printf("input position is invalid \n");
      return __LINE__;
   }

   if (pos == place) {
      pElem = &(pHead->element); 
      printf("change %d element successfully !", pos);
      return 0;
   }

   while (place < pos) {
      place++;
      pHead = pHead->next;
   }
   
   pElem = &(pHead->element);
   
   printf("change %d element successfully !", pos);
   return 0;

}
/*change an element at pos of pHead to a new one *pElem */
/* return 0 successfully, otherwise failed              */
int changeElem(Node *pHead, int pos, elemType* pElem) {
   int place = 1;
   if (pHead == NULL) {
      printf("pHead is NULL, input valid list header !\n");
      return __LINE__;
   }

   if (pos < 1 || pos > sizeofList(pHead)) {
      printf("input position is invalid \n");
      return __LINE__;
   }

   
   if (pos == place) {
      memcpy(&(pHead->element), pElem, sizeof(elemType));
      printf("change %d element successfully !", pos);
      return 0;
   }

   while (place < pos) {
      place++;
      pHead = pHead->next;
   }

   memcpy(&(pHead->element), pElem, sizeof(elemType));
   printf("change %d element successfully !", pos);
   return 0;
  
}
/* insert element 'pElem' into List 'pHead' at 'pos' place*/
/* return List header Node *                              */
Node * insertElem(Node *pHead, int pos, elemType* pElem) {
   Node *pTemp = NULL;
   Node *pPrev = NULL;

   Node *pTempH = pHead;

   int place = 1;

   if (pHead == NULL) {
      printf("pHead is NULL, input valid list header !\n");
      return NULL;
   }

   if (pos < 1 || pos > sizeofList(pHead)) {
      printf("input position is invalid \n");
      return NULL;
   }

   while (place < pos) {
      place++;
      pPrev = pHead;
      pHead = pHead->next;
   }

   pTemp = (Node *)malloc(sizeof(Node));
   if (pTemp == NULL) {
      printf("memory malloc() failed, insert failed... \n");
      return NULL;
   }

   memset(pTemp, 0, sizeof(Node));
   memcpy(&(pTemp->element), pElem, sizeof(elemType));

   (pPrev != NULL) ? (pPrev->next = pTemp) : (pTempH = pTemp);
   pTemp->next = pHead;

   printf("insert at %d successfully !\n", pos);
   return pTempH;

}
