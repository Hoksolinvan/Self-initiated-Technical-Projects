#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#define MAX_WORD_LEN  50

typedef struct patient {
    char           *name;
    int             birth_year;
    int             priority;
    struct patient  *next;
} Patient;

Patient *new_patient(char *, int, int);
Patient *add_front(Patient *, Patient *);
Patient *add_end(Patient *, Patient *);
Patient *add_with_priority(Patient *, Patient *);
Patient *peek_front(Patient *);
Patient *remove_front(Patient *);
void    apply(Patient *, void(*fn)(Patient *, void *), void *arg);

#endif
