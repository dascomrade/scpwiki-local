#include <stdio.h>
#include "lib/cJSON.h"

int main(){
//create the Object
cJSON* json = cJSON_CreateObject();
//Add Fields

//Basic Identifiers
cJSON_AddStringToObject(json, "SRC", "SCP");
cJSON_AddStringToObject(json, "ID", "035");

//Advanced Identifers
cJSON *TagsArr = cJSON_CreateArray();
cJSON_AddItemToArray(TagsArr, cJSON_CreateString("Chemical Hazard"));
cJSON_AddItemToArray(TagsArr, cJSON_CreateString("Sapient"));
cJSON_AddItemToArray(TagsArr, cJSON_CreateString("Manipulative"));
cJSON_AddItemToArray(TagsArr, cJSON_CreateString("Mind Control"));
cJSON_AddItemToObject(json,"Tags", TagsArr);


//class information
cJSON_AddStringToObject(json,"Containment Class", "Keter");
cJSON_AddStringToObject(json,"Disruption Class", "Vlam");
cJSON_AddStringToObject(json,"Risk Class","Critical");


//discovery information
cJSON* LOCATION = cJSON_CreateObject();
cJSON_AddStringToObject(LOCATION, "City", "Venice");
cJSON_AddStringToObject(LOCATION, "Country","Italy");
cJSON_AddStringToObject(LOCATION, "Date", "18██");
cJSON_AddItemToObject(json,"Found in", LOCATION);


//License
cJSON* LICENSE = cJSON_CreateObject();
cJSON_AddStringToObject(LICENSE, "Article:",   " \"SCP-035\" by Kain Pathos Crow, from the SCP Wiki. Source: https://scpwiki.com/scp-035. Licensed under CC BY-SA.");

cJSON_AddItemToObject(json, "Licensing", LICENSE);

//convert Obj to String
char* json_str = cJSON_Print(json);
//Write JSON File
FILE* fp =fopen("035.json", "w");
if(fp ==NULL){

printf("Error: Unable to open the file. \n");
return 1;
}

printf("%s \n", json_str);
fputs(json_str, fp);
fclose(fp);


cJSON_free(json_str);
cJSON_Delete(json);

return 0;



}
