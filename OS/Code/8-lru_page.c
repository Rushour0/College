#include <stdio.h>

int count = 1;

struct Page
{
    char p;
    int use;
};

int search(struct Page exist[20], char key, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (exist[i].p == key)
        {
            exist[i].use = count;
            count++;
            return 1;
        }
    }
    return 0;
}

void display(int n, struct Page exist[20])
{
    for (int i = 0; i < n; i++)
    {
        if (exist[i].p != -1)
            printf("%d\t", exist[i].p);
        else
            printf("- \t");
    }
}

int main()
{

    struct Page exist[20];
    for (int i = 0; i < 20; i++)
    {
        exist[i].p = -1;
    }
    int n, frame, clear = 0, PF = 0, min = 100, index, flag = 0, full = 0;
    char string[20];
    printf("\n\n-------------------- LRU Page Replacement Algorithm --------------------\n\n");
    printf("\nEnter the Number of Pages: ");
    scanf("%d", &n);
    printf("\nEnter the Number of Frames Available: ");
    scanf("%d", &frame);
    printf("\n-------------------- Enter The Reference String --------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Value String[%d]: ", i + 1);
        scanf("%d", &string[i]);
    }
    printf("\n");
    printf("\n-------------------- Page Table --------------------\n\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < frame; j++)
        {
            if (exist[j].p == -1)
            {
                PF++;
                exist[j].p = string[i];
                exist[j].use = count;
                count++;
                full = 0;
                break;
            }
            else
                full = 1;
        }
        if (full == 1)
        {
            for (int j = 0; j < frame; j++)
            {
                clear = search(exist, string[i], frame);
                if (clear == 1)
                    break;
            }
            if (clear == 0)
            {
                PF++;
                min = 100;
                for (int j = 0; j < frame; j++)
                {
                    if (exist[j].use < min)
                    {
                        min = exist[j].use;
                        index = j;
                        flag = 1;
                    }
                }
                if (flag == 1)
                {
                    exist[index].p = string[i];
                    exist[index].use = count;
                    count++;
                }
            }
        }
        display(frame, exist);
        if (clear == 1)
            printf("\tHIT");
        else
            printf("\tMISS");
        printf("\n");
    }
    printf("\nTotal Number of Page Faults are: %d", PF);
    printf("\n\n");
    return 0;
}