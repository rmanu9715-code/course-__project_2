#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct booking
{
    int bookingID;
    char name[50];
    char destination[50];
    int seats;
    float price;

    struct booking *next;
};

struct booking *head = NULL;

/* CREATE BOOKING */

void addBooking()
{
    struct booking *newNode, *temp;

    newNode = (struct booking*)malloc(sizeof(struct booking));

    printf("\nEnter Booking ID: ");
    scanf("%d", &newNode->bookingID);

    printf("Enter Passenger Name: ");
    scanf("%s", newNode->name);

    printf("Enter Destination: ");
    scanf("%s", newNode->destination);

    printf("Enter Number of Seats: ");
    scanf("%d", &newNode->seats);

    printf("Enter Ticket Price: ");
    scanf("%f", &newNode->price);

    newNode->next = NULL;

    if(head == NULL)
        head = newNode;
    else
    {
        temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("\nBooking Added Successfully!\n");
}


/* DISPLAY BOOKINGS */

void displayBookings()
{
    struct booking *temp = head;

    if(temp == NULL)
    {
        printf("\nNo Bookings Available!\n");
        return;
    }

    printf("\n--- Booking Records ---\n");

    while(temp != NULL)
    {
        printf("\nBooking ID: %d", temp->bookingID);
        printf("\nName: %s", temp->name);
        printf("\nDestination: %s", temp->destination);
        printf("\nSeats: %d", temp->seats);
        printf("\nPrice: %.2f\n", temp->price);

        temp = temp->next;
    }
}


/* DELETE BOOKING */

void deleteBooking()
{
    int id;

    struct booking *temp = head, *prev;

    printf("\nEnter Booking ID to Delete: ");
    scanf("%d", &id);

    if(head == NULL)
    {
        printf("\nNo Records Found!\n");
        return;
    }

    if(head->bookingID == id)
    {
        head = head->next;
        free(temp);

        printf("\nBooking Deleted Successfully!\n");
        return;
    }

    while(temp != NULL && temp->bookingID != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("\nBooking Not Found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("\nBooking Deleted Successfully!\n");
}


/* SEARCH BOOKING */

void searchBooking()
{
    int id;

    struct booking *temp = head;

    printf("\nEnter Booking ID to Search: ");
    scanf("%d", &id);

    while(temp != NULL)
    {
        if(temp->bookingID == id)
        {
            printf("\nBooking Found!");
            printf("\nName: %s", temp->name);
            printf("\nDestination: %s", temp->destination);
            printf("\nSeats: %d", temp->seats);
            printf("\nPrice: %.2f\n", temp->price);

            return;
        }

        temp = temp->next;
    }

    printf("\nBooking Not Found!\n");
}


/* UPDATE BOOKING */

void updateBooking()
{
    int id;

    struct booking *temp = head;

    printf("\nEnter Booking ID to Update: ");
    scanf("%d", &id);

    while(temp != NULL)
    {
        if(temp->bookingID == id)
        {
            printf("Enter New Name: ");
            scanf("%s", temp->name);

            printf("Enter New Destination: ");
            scanf("%s", temp->destination);

            printf("Enter New Seats: ");
            scanf("%d", &temp->seats);

            printf("Enter New Price: ");
            scanf("%f", &temp->price);

            printf("\nBooking Updated Successfully!\n");

            return;
        }

        temp = temp->next;
    }

    printf("\nBooking Not Found!\n");
}


/* MAIN MENU */

int main()
{
    int choice;

    while(1)
    {
        printf("\n====== Travel Booking Platform ======\n");

        printf("\n1. Add Booking");
        printf("\n2. Delete Booking");
        printf("\n3. Update Booking");
        printf("\n4. Search Booking");
        printf("\n5. Display All Bookings");
        printf("\n6. Exit");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addBooking();
                break;

            case 2:
                deleteBooking();
                break;

            case 3:
                updateBooking();
                break;

            case 4:
                searchBooking();
                break;

            case 5:
                displayBookings();
                break;

            case 6:
                printf("\nThank You for Using Travel Booking Platform!\n");
                exit(0);

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}
