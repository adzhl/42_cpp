#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <number_of_runs> <number_count_per_run>"
    echo "Example: $0 20 100"
    exit 1
fi

RUNS=$1
RUN_SIZE=$2
FAIL=0

for ((i = 1; i <= RUNS; ++i)); do
    INPUT=$(shuf -i 1-100000 -n "$RUN_SIZE")

    OUTPUT=$(./PmergeMe $INPUT 2>&1)

    COMP=$(echo "$OUTPUT" | grep "No of comparisons" | sed 's/[^0-9]*//g')
    THEO=$(echo "$OUTPUT" | grep "Max number of comparisons allowed" | sed 's/[^0-9]*//g')

    if [ -z "$COMP" ] || [ -z "$THEO" ]; then
        echo "❌ Run $i: Could not parse output."
        echo "$OUTPUT"
        ((FAIL++))
        continue
    fi

    if [ "$COMP" -le "$THEO" ]; then
        echo "✅ Run $i: $COMP ≤ $THEO"
    else
        echo "❌ Run $i: $COMP > $THEO"
        ((FAIL++))
    fi
done

if [ $FAIL -eq 0 ]; then
    echo -e "\n🎉 All $RUNS runs succeeded."
else
    echo -e "\n⚠️ $FAIL out of $RUNS runs failed."
fi
