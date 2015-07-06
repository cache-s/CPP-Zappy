
for ((i = 0; i < 100; i++))
do
    sleep 0.01
    nc 0 4242
    echo "titi"
done
