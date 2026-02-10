#!/bin/bash -f
ls -al | awk '
{
if($3!="")
if($3 in files){
files[$3]=files[$3]+1;
}
else{
files[$3]=1;
}
}
END{
for(key in files){
print key "has" files[key] "files.\n";
}
}
'
