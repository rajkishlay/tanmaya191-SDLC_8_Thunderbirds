/**
 * @file series.c
 * @author Saivardhan Reddy (ssaivardhan1919@gmail.com)
 * @brief To calculate the capacitance and inductance in series connection
 * @version 0.1
 * @date 2021-08-22
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <stdio.h>
#include "../inc/Thunderbirds.h"
/**
 * @brief calculation of series capacitance
 *
 * @param number_of_capacitors
 * @param capacitor
 * @return double
 */

double series_capacitance(int number_of_capacitors, double capacitor[])
{
   int loop_counter = 0;
   double series_equivalent_capacitance = 0;

   for (loop_counter = 0; loop_counter < number_of_capacitors; loop_counter++)
   {
      series_equivalent_capacitance = series_equivalent_capacitance + (1.0 / capacitor[loop_counter]);
   }
   series_equivalent_capacitance = 1.0 / series_equivalent_capacitance;

   return series_equivalent_capacitance;
}
/**
 * @brief
 *
 * @param number_of_inductors
 * @param inductor
 * @return double
 */
double series_inductance(int number_of_inductors, double inductor[])
{
   int loop_counter = 0;
   double series_equivalent_inductor = 0;

   for (loop_counter = 0; loop_counter < number_of_inductors; loop_counter++)
   {
      series_equivalent_inductor = series_equivalent_inductor + inductor[loop_counter];
   }

   return series_equivalent_inductor;
}

/**
 * @brief
 *
 * @param number_of_resistors
 * @param resistor
 * @return double
 */
double series_resistance(int number_of_resistors, double resistor[])
{
   int loop_counter = 0;
   double series_equivalent_resistor = 0;

   for (loop_counter = 0; loop_counter < number_of_resistors; loop_counter++)
   {
      series_equivalent_resistor = series_equivalent_resistor + resistor[loop_counter];
   }

   return series_equivalent_resistor;
}
/**
 * @brief choice taken from user for which passive element equivalent series is to be found
 *
 * @return int
 */
int series()
{
   int choice;
   printf("\nEnter which passive element's series equivalent you want to find \n");
   printf("\n Enter \nPress 1 'C' for capacitance \nPress 2 'I' for inductance \nPress 3 'R' for resistance \n");
   scanf("%d", &choice);


   if (choice == 1)
   {
      int number_of_capacitors, loop_counter = 0;
      double capacitor[100], series_equivalent_capacitance = 0;

      printf("\nEnter the number of Capacitors : ");
      scanf("%d", &number_of_capacitors);

      printf("\nEnter Value of Each Capacitance in microFarads: ");
      for (loop_counter = 0; loop_counter < number_of_capacitors; loop_counter++)
      {
         printf("\n Capacitance value%d : ", loop_counter + 1);
         scanf("%lf", &capacitor[loop_counter]);
      }

      series_equivalent_capacitance = series_capacitance(number_of_capacitors,capacitor);
      printf("\nEquivalent Series Capacitance : %lf microFarads", series_equivalent_capacitance);
   }
   if (choice == 2)
   {
      int number_of_inductors, loop_counter = 0;
      double inductor[100], series_equivalent_inductor = 0;

      printf("\nEnter the number of Inductors : ");
      scanf("%d", &number_of_inductors);

      printf("\nEnter Value of Each Inductance in milli Henry : ");
      for (loop_counter = 0; loop_counter < number_of_inductors; loop_counter++)
      {
         printf("\n Inductor value%d : ", loop_counter + 1);
         scanf("%lf", &inductor[loop_counter]);
      }

      series_equivalent_inductor = series_inductance(number_of_inductors, inductor);
      printf("\nEquivalent Series Inductance : %lf milli Henry", series_equivalent_inductor);
   }
      if (choice == 3)
   {
      int number_of_resistors, loop_counter = 0;
      double resistor[100], series_equivalent_resistor = 0;

      printf("\nEnter the number of Resistors : ");
      scanf("%d", &number_of_resistors);

      printf("\nEnter Value of Each Resistance in milli Henry : ");
      for (loop_counter = 0; loop_counter < number_of_resistors; loop_counter++)
      {
         printf("\n Resistor value%d : ", loop_counter + 1);
         scanf("%lf", &resistor[loop_counter]);
      }

      series_equivalent_resistor = series_resistance(number_of_resistors, resistor);
      printf("\nEquivalent Series Resistance : %lf milli Ohm", series_equivalent_resistor);
   }
   return 0;
}
