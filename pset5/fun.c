const char* extract(char *Line)
{
    char* st = strstr(Line," ");
    int size = strlen(Line) - strlen(st);
    char out[size+2];
    memset(out, '\0', sizeof(out));
    strncpy(out, Line,size);
    Line = strstr(st,&st[1]);
    return out;
}



     char* st = strstr(Line," ");
     int size = strlen(Line) - strlen(st);  
     char out[size+2];
     memset(out, '\0', sizeof(out));
     strncpy(out, Line,size);
     Line = strstr(st,&st[1]);
