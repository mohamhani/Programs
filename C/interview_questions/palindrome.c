#include <stdio.h>
#include <string.h>

void is_palindrome(char *word)
{
    int left = 0;
    int right = strlen(word) - 1;
    while(right > left)
    {
        if(*(word + left) != *(word + right))
        {
            printf("%s is not palindrome\n", word);
            return;
        }
        left++;
        right--;
    }

    printf("%s is palindrome\n", word);

}

int main(int argc, const char *argv[])
{
    is_palindrome("abba");
    is_palindrome("geeks");

    return 0;
}