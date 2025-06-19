#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <number_of_runs> <number_count_per_run>"
    echo "Example: $0 20 100"
    exit 1
fi

RUNS=$1
RUN_SIZE=$2
FAIL=0
SORT_FAIL=0

for ((i = 1; i <= RUNS; ++i)); do
    INPUT=$(shuf -i 1-100000 -n "$RUN_SIZE")
    OUTPUT=$(./PmergeMe $INPUT 2>&1)
    
    SORT_STATUS=$(echo "$OUTPUT" | grep -E "Sorted!|Not sorted!")
    COMP=$(echo "$OUTPUT" | grep "No of comparisons for std::vector" | grep -o '[0-9]\+$')
    MAX=$(echo "$OUTPUT" | grep "Max number of comparisons allowed" | grep -o '[0-9]\+$')
    
    if [ -z "$COMP" ] || [ -z "$MAX" ]; then
        echo "❌ Run $i: Could not parse output."
        echo "$OUTPUT"
        ((FAIL++))
        continue
    fi
    
    if [[ "$SORT_STATUS" == *"Not sorted!"* ]]; then
        echo "❌ Run $i: Array was not sorted correctly!"
        ((SORT_FAIL++))
        ((FAIL++))
    elif [[ "$SORT_STATUS" != *"Sorted!"* ]]; then
        echo "❌ Run $i: Could not determine sort status!"
        ((SORT_FAIL++))
        ((FAIL++))
    fi
    
    if [ "$COMP" -le "$MAX" ]; then
        echo "✅ Run $i: $COMP ≤ $MAX (Status: $SORT_STATUS)"
    else
        echo "❌ Run $i: $COMP > $MAX (Status: $SORT_STATUS)"
        ((FAIL++))
    fi
done

if [ $FAIL -eq 0 ]; then
    echo -e "\n🎉 All $RUNS runs succeeded."
else
    echo -e "\n⚠️ $FAIL out of $RUNS runs failed."
    echo -e "⚠️ $SORT_FAIL of these failures were due to incorrect sorting."
fi