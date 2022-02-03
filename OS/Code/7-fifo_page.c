#include <stdio.h>

int FIFO_page_replacement(int page_frame[10], int referenceString[20], int frames, int n)
{
    int i, j, hit, pageFaults = 0;
    for (i = 0; i < n; i++)
    {
        hit = 0;
        // searching already present or not
        for (j = 0; j < frames; j++)
        {
            if (referenceString[i] == page_frame[j])
            {
                hit++;
            }
        }
        if (hit == 0)
            pageFaults++;
        // if not hit
        if ((pageFaults <= frames) && (hit == 0))
        {
            page_frame[i] = referenceString[i];
        }
        else if (hit == 0)
        {
            page_frame[(pageFaults - 1) % frames] = referenceString[i];
        }
        printf("\n%d Pass: ", i + 1);
        for (j = 0; j < frames; j++)
        {
            printf("%d\t", page_frame[j]);
        }
    }
    return pageFaults;
}

int main()
{
    int frames, n, i, page_fault;
    int page_frame[10];
    int page_reference[20];
    for (i = 0; i < 10; i++)
        page_frame[i] = -1;
    printf("\nEnter no of Page Frames: ");
    scanf("%d", &frames);
    printf("\nEnter no of Pages to be Entered: ");
    scanf("%d", &n);
    printf("\nEnter Page References: ");
    for (i = 0; i < n; i++)
        scanf("%d", &page_reference[i]);
    page_fault = FIFO_page_replacement(page_frame, page_reference, frames, n);
    printf("\n\nTotal No of Page Faults: %d", page_fault);
    printf("\n");
    return 0;
}