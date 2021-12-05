#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "svg.h"

int maxValue(int arr[]){
    int max_value = arr[0];
    for (int i = 1; i < 12; ++i) {
        if ( arr[i] > max_value ) {
            max_value = arr[i];
        }
    }
    return max_value;
}
  
int main()
{
    char buffer[1024];
    char data_month[12][1024];
    char text_expenses[12][1024];
    int data_expenses[12];
    char sub_text[3];
    FILE* fp = fopen("C:\\Users\\USER\\C\\C\\SVG_CHART_PROJECT\\data.csv", "r");
  
    if (!fp)
        printf("Can't open file\n");
  
    else {
        int row = 0;
        int column = 0;
  
        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;
  
            char* value = strtok(buffer, ",");
  
            while (value) {
                if (column == 0) {
                    strcpy(data_month[row - 1],value);
                }

                if (column == 1) {
                    data_expenses[row - 1] = atoi(value);
                    strcpy(text_expenses[row - 1],value);
                }
                value = strtok(NULL, ", ");
                column++;
            }
        }

        fclose(fp);
    }
    int max_value = maxValue(data_expenses);

    svg* psvg;
    psvg = svg_create(1500, 700);

    if(psvg == NULL)
    {
        puts("psvg is NULL");
    }
    else
    {
        svg_text(psvg, 50, 30, "sans-serif", 20, "#000000", "#000000", "Expenses in month");
        svg_line(psvg, "#000000", 2, 50, 50, 50, 600);
        svg_line(psvg, "#000000", 2, 50, 600, 1324, 600);

        int x = 100;
        for (int i = 0; i < 12; i++)
        {
            int expenses = (500*data_expenses[i])/max_value;
            svg_rectangle(psvg, 50, expenses, x, 600 - expenses, "#00FF00", "#000000", 0, 0, 0);
            svg_text(psvg, x, 625, "sans-serif", 14, "#000000", "#000000", data_month[i]);
            svg_text(psvg, x + 12, 590 - expenses, "sans-serif", 14, "#000000", "#000000", text_expenses[i]);
            x += 100;
        }

        char result[100];
        int buff = max_value;
        if (max_value <= 100)
        {
            while (true)
            {
                int set_value = (500*buff)/max_value;
                sprintf(result, "%d", buff);
                svg_text(psvg, 10, 600 - set_value, "sans-serif", 14, "#000000", "#000000", result);
                svg_line(psvg, "#000000", 2, 45, 600 - set_value, 55, 600 - set_value);
                buff -= 10;
                if(buff == 0){
                    break;
                }
            }
            
        }
        else if (max_value <= 1000)
        {
            while (true)
            {
                int set_value = (500*buff)/max_value;
                sprintf(result, "%d", buff);
                svg_text(psvg, 10, 600 - set_value, "sans-serif", 14, "#000000", "#000000", result);
                svg_line(psvg, "#000000", 2, 45, 600 - set_value, 55, 600 - set_value);
                buff -= 100;
                if(buff == 0){
                    break;
                }
            }
            
        }
        else if (max_value <= 10000)
        {

            while (true)
            {
                int set_value = (500*buff)/max_value;
                sprintf(result, "%d", buff);
                svg_text(psvg, 10, 600 - set_value, "sans-serif", 14, "#000000", "#000000", result);
                svg_line(psvg, "#000000", 2, 45, 600 - set_value, 55, 600 - set_value);
                buff -= 1000;
                if(buff == 0){
                    break;
                }
            }
            
        }
        else if (max_value <= 100000)
        {

            while (true)
            {
                int set_value = (500*buff)/max_value;
                sprintf(result, "%d", buff);
                svg_text(psvg, 10, 600 - set_value, "sans-serif", 14, "#000000", "#000000", result);
                svg_line(psvg, "#000000", 2, 45, 600 - set_value, 55, 600 - set_value);
                buff -= 10000;
                if(buff == 0){
                    break;
                }
            }
            
        }
        else if (max_value <= 1000000)
        {
            while (true)
            {
                int set_value = (500*buff)/max_value;
                sprintf(result, "%d", buff);
                svg_text(psvg, 10, 600 - set_value, "sans-serif", 14, "#000000", "#000000", result);
                svg_line(psvg, "#000000", 2, 45, 600 - set_value, 55, 600 - set_value);
                buff -= 100000;
                if(buff == 0){
                    break;
                }
            }
            
        }

        svg_finalize(psvg);
        svg_save(psvg, "chart.svg");
        svg_free(psvg);
    }


    return 0;
}