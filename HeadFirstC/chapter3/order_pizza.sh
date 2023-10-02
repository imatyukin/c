gcc 3_02-getopt.c -o order_pizza
echo '# ./getopt Anchovies'
./order_pizza Anchovies
echo '================================ RESTART ================================'
echo '# ./order_pizza Anchovies Pineapple'
./order_pizza Anchovies Pineapple
echo '================================ RESTART ================================'
echo '# ./order_pizza -d now Anchovies Pineapple'
./order_pizza -d now Anchovies Pineapple
echo '================================ RESTART ================================'
echo '# ./order_pizza -d now -t Anchovies Pineapple'
./order_pizza -d now -t Anchovies Pineapple
echo '================================ RESTART ================================'
echo '# ./order_pizza -d'
./order_pizza -d
