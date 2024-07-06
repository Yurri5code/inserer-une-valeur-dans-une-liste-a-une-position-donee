#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node {
    int data;
    node* next;
};

typedef struct element element;
struct element {
    node* first;
};

element* initialisation() {
    element* element = malloc(sizeof(*element));
    node* init = malloc(sizeof(*init));

    if(element == NULL || init == NULL) {
        exit(EXIT_FAILURE);
    }
    init->data = 0;
    init->next = NULL;
    element->first = init;

    return element;
}

void insertValue(element* head,const int data) {
    node* nouveau = malloc(sizeof(*nouveau));

    if(nouveau == NULL || head == NULL) {
        exit(EXIT_FAILURE);
    }
    nouveau->data = data;
    nouveau->next = head->first;
    head->first = nouveau;
}

void inserAtposition(element *head,int data,int index) {
    node *newValue = malloc(sizeof(*newValue)),*current = head->first,*q = NULL;
    if(newValue == NULL || head->first == NULL) {
        exit(EXIT_FAILURE);
    }
    current = head->first;
    newValue->data = data;

    if(index == 0) {
        newValue->next = current;
        head->first = newValue;
        return;
    }
    else {
        for(int i = 0;i<index;i++) {
            q = current;
            current = current->next;
        }
    }

    if(q == NULL) {
        exit(EXIT_FAILURE);
    }
    newValue->next = current;
    q->next = newValue;
}

void affiche(const element* head) {
    node* current = head->first;
    while(current!=NULL) {
        printf("%d->",current->data);
        current = current->next;
    }
    printf(("NULL"));
}

void suppression(element* head) {
    node *current = head->first,*q=current->next;
    while(current!=NULL) {
        q = current->next;
        free(current);
        current = q;
    }
    head->first = NULL;
}

int verif(const element* head) {
    if(head->first == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int main(void)
{
    element *liste = initialisation();
    printf("entrez le nombre d'element de la liste de depart :  \n");
    int nbr = 0,valeur = 0, index = 0;
    scanf("%d",&nbr);

    for(int i = 0;i<nbr;i++) {
        int value = 0;
        printf(" \n entrez la valeur numero %d de la liste   :   ",i+1);
        scanf("%d",&value);
        insertValue(liste,value);
    }
    printf("\n affichage de la liste avant l'entree de la nouvelle valeur \n");
    affiche(liste);

    printf("\n entrez la valeur a inserer : ");
    scanf("%d",&valeur);
    printf("\n entrez la position ou sera entrez la valeur :  ");
    scanf("%d",&index);
    inserAtposition(liste,valeur,index);
    printf("\n affichage de la nouvelle liste : \n");
    affiche(liste);
    printf("\n suppression de la liste....\n");
    suppression(liste);
    printf("verification de la liste supprimee \n");
    int verification = 0;
    verification = verif(liste);
    if(verification == 1) {
        printf("\n la liste a ete supprimee...\n");
    }
    else {
        printf("\n la suppression a echouee...\n");
    }

    return 0;
}
