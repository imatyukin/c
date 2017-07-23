gcc geo2json.c -o geo2json
./geo2json < gpsdata.csv > output.json
echo $?
