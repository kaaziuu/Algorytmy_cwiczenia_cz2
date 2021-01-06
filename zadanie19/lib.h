typedef struct HUNode
{
    char ch;
    int count;
    struct HUNode *next;
    struct HUNode *left;
    struct HUNode *right;
} HUNode;


HUNode *compressWord(HUNode *head, char *word);
HUNode *worldToList(HUNode *head, char *word);

void print(HUNode *head, int deep);