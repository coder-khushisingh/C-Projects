#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Book{
    int id;
    char title[50];
    char author[50];
    int copies;

};

void addBook(FILE*fp){
    struct Book b;
    printf("\n Enter book ID: ");
    scanf("%d",&b.id);
    printf("\n Enter book title:");
    scanf("%s",b.title);
    printf("\n Enter Author:");
    scanf("%s",b.author);
    printf("\n Enter number of copies:");
    scanf("%d",&b.copies);
    fseek(fp,0,SEEK_END);
    fwrite(&b,sizeof(b),1,fp);

}

void listBooks(FILE*fp){
    struct Book b;
    rewind(fp);
    while(fread(&b,sizeof(b),1,fp)==1)
    {
        printf("ID:%d,Title:%s,Author:%s,copies:%d\n",b.id,b.title,b.author,b.copies);

    }
}

void searchBook(FILE*fp){
    int id, found=0;
    struct Book b;
    printf("Enter Book ID:");
    scanf("%d",&id);
    rewind(fp);
    while(fread(&b,sizeof(b),1,fp)==1)
    {
        if(b.id==id)
        {
            printf("ID:%d,Title:%s,Author:%s,copies:%d\n",b.id,b.title,b.author,b.copies);
            found =1;
            break;
        }
    }
    if(!found)
        printf("Book not found.\n");
}

void deletebook(FILE*fp){
    int id,found=0;
    struct Book b;
    FILE*temp=fopen("temp.dat","wb");
    printf("Enter book ID to delete:\n");
    scanf("%d",&id);
    rewind(fp);
    while(fread(&b,sizeof(b),1,fp)==1){
        if(b.id==id){
            fwrite(&b,sizeof(b),1,temp);
        }else{
            found=1;
        }
    }
    fclose(fp);
    fclose(temp);
    remove("library.dat");
    rename("temp.dat","library.dat");
    if(found)
        printf("Book Deleted Successfully.\n");
    else
        printf("Book not found.\n");
}

int main()
{
    FILE*fp=fopen("library.dat","rb+");
    if(fp==NULL)
        fp=fopen("library.dat","wb+");
    int choice;
    while(1){
        printf("\n1.Add Book \n2.List Books \n3.Search Book \n4.Delete Book \n5.Exit \n Enter Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:addBook(fp);break;
            case 2:listBooks(fp);break;
            case 3:searchBook(fp);break;
            case 4:fclose(fp);deletebook(fp);
            fp=fopen("library.dat","rb+");break;
            case 5:fclose(fp);exit(0);
            default:printf("Invalid choice\n");
        }
    }
    return 0;
    
}
