#ifndef ARRAYADT_H_
#define ARRAYADT_H

#ifdef __cplusplus
extern "C" {
#endif
typedef struct arrayADT_ arrayADT_t;

typedef struct arrayADT_
{
    void* array;
    int size;
    int length;
    /*initialize operation*/
    void (*initialize)(const arrayADT_t* arr);
    /*swap operation*/
    void (*swap)(int* , int *);
    /*length operation*/
    int (*getLength)(arrayADT_t adt);
    /* reverse operation */
    void (*reverse)(arrayADT_t* arr);
    /* rorate left operation */
    void (*rotateLeft)(arrayADT_t* arr, int count);
    /* rotate right operation */
    void (*rotateReft)(arrayADT_t* arr, int count);
    /*Display operation*/
    void (*display)(arrayADT_t arr);
    /*insert operation*/
    void (*insert)(arrayADT_t* arr , int data);
    /*delete operation*/
    void (*delete)(arrayADT_t* arr , int data);
    /* search operation*/
    int (*search)(const arrayADT_t arr, int data);
    /* merge operation */
    int (*merge)(arrayADT_t* from , arrayADT_t* to);
}arayADT_t;









extern arayADT_t arrayADT;




#ifdef __cplusplus
}
#endif



#endif





