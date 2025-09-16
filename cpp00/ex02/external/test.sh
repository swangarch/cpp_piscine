awk '{print substr($0, 19)}' my.log > temp1.txt
awk '{print substr($0, 19)}' 19920104_091532.log > temp2.txt

diff temp1.txt temp2.txt > /dev/null && echo "diff OK" || echo "diff KO"
rm temp1.txt temp2.txt
