
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Bst.h"

int main()
{   char fname[20];
    int option, no, no1, no2, no3;
    struct node* root;
    initBST(&root);
    int ext = 1;
    while(ext == 1){
        printf("Choose from the following options - (1 - Insert Node, 2 - Remove Node,3 - Search Node \n4 - Postorder Traversal,5 - Display Level , 6 - Destroy Tree)\n");
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("Enter Value of Node to Insert : ");
                scanf("%d",&no);
                while ((getchar()) != '\n');
                printf("Enter Name of Node to Insert : ");
                gets(fname);
                root = insertNode(root, no, fname);
                break;
            case 2:
                printf("Enter Value of Node to Remove : ");
                scanf("%d",&no3);
                root = remove_Node(root, no3);

                break;
            case 3:
                printf("Enter Value of Node to Search : ");
                scanf("%d",&no1);
                if(search_BST(root, no1) == true)
                    printf("%i is present in the BST.", no1);
                else
                    printf("%i is not present in the BST.", no1);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
            printf("Enter Level to Display : ");
            scanf("%d",&no2);
            Display_Level(root, no2);
                break;
            case 6:
                destroyTree(root);
                break;
            default:
                printf("Enter From The Given Options Only");
        }
        printf("\nDo you want to continue? 1-yes,0-no ");
        scanf("%d", &ext);
    }

    return 0;
}


