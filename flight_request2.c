#include <stdio.h>

void landing_takeoff(int choice);
void slots_left(int land_hour, int take_hour);
void display_menu();

int landing_slots[24], takeoff_slots[24], slots_left_landing=24, slots_left_takeoff=24, hours[24];
int landing_hour, takeoff_hour;

int main() {
  int choice;

  for (int i=0; i<24; i++) {
    landing_slots[i] = 0;
    takeoff_slots[i] = 0;
    hours[i] = i+1;
  }
  
  do {
    printf("Welcome to KLIA Internationnal Airport\n");
    printf("1. Request for Landing\n2. Request for Take-off\n3. Display schedule\n4. Exit\nSelection: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
      landing_takeoff(choice);
      continue;
      case 2:
      landing_takeoff(choice);
      continue;
      case 3:
      display_menu();
      continue;
      case 4:
      break;
      default:
      printf("Invalid choice. Please try again.\n");
      continue;
    }
  } while (choice != 4);
}

void landing_takeoff(int choice) {
  if (choice == 1) {
    printf("There are %d slots available for landing\nEnter Landing hour [1 to 24]: ", slots_left_landing);
    scanf("%d", &landing_hour);
    if (landing_hour >= 1 && landing_hour <= 24) {
      slots_left(landing_hour, 0);
    } else {
      printf("Invalid hour!");
    }
  } else if (choice == 2) {
    printf("There are %d slots available for take-off\nEnter Take-off hour [1 to 24]: ", slots_left_takeoff);
    scanf("%d", &takeoff_hour);
    if (takeoff_hour >= 1 && takeoff_hour <= 24) {
      slots_left(0, takeoff_hour);
    } else {
      printf("Invalid hour!");
    }
  }
}

void slots_left(int land_hour, int take_hour) {
  if (land_hour != 0) {
    if (landing_slots[land_hour-1] == 0) {
      landing_slots[land_hour-1] = 1;
      slots_left_landing--;
      printf("Request successful! Thank you.\n");
    }
    else {
      printf("The slot has already been requested!\n");
    }
  }
if (take_hour != 0) {
    if (takeoff_slots[take_hour-1] == 0) {
      takeoff_slots[take_hour-1] = 1;
      slots_left_takeoff--;
      printf("Request successful! Thank you.\n");
    } else {
      printf("The slot has already been requested!\n");
    }
  }
}

void display_menu() {
  char hour_runway[2] = {'H', 'R'};
  int counter = 0;
  printf("Runway 1\n");
  for (int i=0; i<2; i++) {
    for (int j=0; j<2; j++) {
      printf("(%c) ", hour_runway[j]);
      for (int k=0; k<12; k++) {
        if (hour_runway[j] == 'H') {
          printf("%d ", hours[k+counter]);
        } else if (hour_runway[j] == 'R') {
          if (landing_slots[k+counter] == 1) {
            printf("L ");
          } else {
            printf("%d ", landing_slots[k+counter]);
          }
        }
      }
      printf("\n");
    }
    counter+=12;
    printf("\n");
  }
  counter = 0;
  printf("Runway 2\n");
  for (int i=0; i<2; i++) {
    for (int j=0; j<2; j++) {
      printf("(%c) ", hour_runway[j]);
      for (int k=0; k<12; k++) {
        if (hour_runway[j] == 'H') {
          printf("%d ", hours[k+counter]);
        } else if (hour_runway[j] == 'R') {
          if (takeoff_slots[k+counter] == 1) {
            printf("T ");
          } else {
            printf("%d ", takeoff_slots[k+counter]);
          }
        }
      }
      printf("\n");
    }
    counter+=12;
    printf("\n");
  }
}