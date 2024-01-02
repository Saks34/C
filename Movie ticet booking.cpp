#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct movie {
    int id;
    char name[50];
    char genre[50];
    float rating;
    int duration;
    int available_seats;
};

struct user {
    int id;
    char name[50];
    char email[50];
};

struct booking {
    int id;
    int movie_id;
    int user_id;
    int num_tickets;
};

void show_movies() {
    FILE *fptr;
    struct movie m;
    fptr = fopen("movies.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }
    printf("ID\tName\t\tGenre\t\tRating\tDuration (min)\tAvailable Seats\n");
    while (fread(&m, sizeof(m), 1, fptr)) {
        printf("%d\t%s\t\t%s\t\t%.1f\t%d\t\t%d\n", m.id, m.name, m.genre, m.rating, m.duration, m.available_seats);
    }
    fclose(fptr);
}

void register_user() {
    FILE *fptr;
    struct user u;
    fptr = fopen("users.txt", "a");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", u.name);
    printf("Enter email: ");
    scanf("%s", u.email);
    u.id = rand() % 1000 + 1;
    fwrite(&u, sizeof(u), 1, fptr);
    printf("User registered successfully. Your user ID is %d.\n", u.id);
    fclose(fptr);
}

void book_ticket() {
    FILE *fptr, *booking_fptr;
    struct movie m;
    struct user u;
    struct booking b;
    int movie_id, user_id, num_tickets;
    fptr = fopen("movies.txt", "r+");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }
    printf("Enter movie ID: ");
    scanf("%d", &movie_id);
    while (fread(&m, sizeof(m), 1, fptr)) {
        if (m.id == movie_id) {
            printf("Enter user ID: ");
            scanf("%d", &user_id);
            FILE *user_fptr = fopen("users.txt", "r");
            while (fread(&u, sizeof(u), 1, user_fptr)) {
                if (u.id == user_id) {
                    printf("Enter number of tickets: ");
                    scanf("%d", &num_tickets);
                    if (num_tickets > m.available_seats) {
                        printf("Sorry, only %d seats available for this movie.\n", m.available_seats);
                        fclose(user_fptr);
                        fclose(fptr);
                        return;
                    }
                    m.available_seats -= num_tickets;
                    fseek(fptr, -sizeof(m), SEEK_CUR);
                    fwrite(&m, sizeof(m), 1, fptr);
                    fclose(user_fptr);
                    b.id = rand() % 1000 + 1;
                    b.movie_id = movie_id;
                    b.user_id = user_id;
                    b.num_tickets = num_tickets;
                    booking_fptr = fopen("bookings.txt", "a");
                    if (booking_fptr == NULL) {
                        printf("Error opening file.\n");
                        fclose(fptr);
                        return;
                    }
                fwrite(&b, sizeof(b), 1, booking_fptr);
                printf("Ticket booked successfully. Your booking ID is %d.\n", b.id);
                fclose(booking_fptr);
                fclose(fptr);
                return;
            }
        }
        printf("User not found.\n");
        fclose(user_fptr);
        fclose(fptr);
        return;
    }
}
printf("Movie not found.\n");
fclose(fptr);
}

void cancel_ticket() {
FILE *fptr, *booking_fptr;
struct movie m;
struct booking b;
int booking_id, movie_id, user_id, num_tickets;
fptr = fopen("movies.txt", "r+");
if (fptr == NULL) {
printf("Error opening file.\n");
return;
}
printf("Enter booking ID: ");
scanf("%d", &booking_id);
booking_fptr = fopen("bookings.txt", "r");
if (booking_fptr == NULL) {
printf("Error opening file.\n");
fclose(fptr);
return;
}
while (fread(&b, sizeof(b), 1, booking_fptr)) {
if (b.id == booking_id) {
movie_id = b.movie_id;
user_id = b.user_id;
num_tickets = b.num_tickets;
while (fread(&m, sizeof(m), 1, fptr)) {
if (m.id == movie_id) {
m.available_seats += num_tickets;
fseek(fptr, -sizeof(m), SEEK_CUR);
fwrite(&m, sizeof(m), 1, fptr);
break;
}
}
fseek(booking_fptr, -sizeof(b), SEEK_CUR);
fwrite("", sizeof(b), 1, booking_fptr);
printf("Ticket cancelled successfully.\n");
fclose(booking_fptr);
fclose(fptr);
return;
}
}
printf("Booking not found.\n");
fclose(booking_fptr);
fclose(fptr);
}
void payment_options() {
printf("Payment options:\n1. Credit card\n2. Debit card\n3. Net banking\n4. Wallet\n");
}

int main() {
int choice;
while (1) {
printf("\nWelcome to the Movie Ticket Booking System\n");
printf("1. Show current movies\n");
printf("2. Register\n");
printf("3. Book ticket\n");
printf("4. Cancel ticket\n");
printf("5. Payment options\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
show_movies();
break;
case 2:
register_user();
break;
case 3:
book_ticket();
break;
case 4:
cancel_ticket();
break;
case 5:
payment_options();
break;
case 6:
printf("Thank you for using the Movie Ticket Booking System.\n");
return 0;
default:
printf("Invalid choice. Please try again.\n");
}
}
}

