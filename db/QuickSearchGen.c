#include <stdio.h>
#include "lib/cJSON.h"

int main(){
//create the Object
cJSON* qSearch = cJSON_CreateObject();
//Add Fields

//Identifiers
cJSON_AddStringToObject(qSearch, "MAIN", "1");
cJSON_AddStringToObject(qSearch,"MAIN","2");




//convert Obj to String
char* json_str = cJSON_Print(qSearch);
//Write JSON File
FILE* fp =fopen("QuickSearch.json", "w");
if(fp ==NULL){

printf("Error: Unable to open the file. \n");
return 1;
}

printf("%s \n", json_str);
fputs(json_str, fp);
fclose(fp);


cJSON_free(json_str);
cJSON_Delete(qSearch);

return 0;



}
