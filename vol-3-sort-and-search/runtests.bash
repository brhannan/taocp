#!/bin/bash
./test_comp_count

exit_code=$?

if [[ exit_code -eq 0 ]]; then
    echo "Test suite passed."
else
    echo "Test suite failed with exit code $exit_code."
fi
