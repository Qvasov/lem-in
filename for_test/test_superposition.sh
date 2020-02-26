#!/bin/sh
SCRIPT_DIR=$(cd $(dirname $0) && pwd)

cd ${SCRIPT_DIR}
# SOLUTION
./generator --big-superposition > test_map
./lem-in < test_map > test_solution

# PRINT
tail -1 test_map | sed 's/#Here is the n/N/g'
echo "Your number of lines:     \c"
echo "$(diff test_map test_solution | wc -l) - 2" | bc
echo "Difference:               \c"
echo " $(echo "$(diff test_map test_solution | wc -l) - 2" | bc) - \
	$(tail -1 test_map | sed 's/#Here is the number of lines required://g')" | bc

rm -rf test_map test_solution
