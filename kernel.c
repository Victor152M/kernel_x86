void kmain(void)
{
    const char *str = "my first kernel";
    char *vidptr = (char*)0xb8000; //video memory begins here
    usigned int i = 0;
    usigned int j = 0;

    /*
    this loop clear the scrren
    there are 25 lines, each of 80 columns
    each element takes 2 bytes
    */
    while(j < 80 * 25 * 2){
        vidptr[j] = ' ';
        /* attribute byte - light grey on black screen */
        vidptr[j+1] = 0x07;
        j = j + 2;
    }

    j = 0;

    /* this loop writes the string to video memory*/
    while(str[j] != '\0'){
        /*the character's ascii*/
        vidptr[i] = str[j];

        /*attribute-byte: give character black background and light grey fg*/
        vidptr[i+1] = 0x07;
        ++j;
        i = i + 2;
    }
    return ;
}