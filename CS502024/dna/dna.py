import csv
import sys


def main():
    if len(sys.argv) != 3:
        print("Error - Try: python dna.py database.csv sequence.txt")
        return

    dnas = []
    strs = []
    with open(sys.argv[1]) as fdb:
        reader = csv.DictReader(fdb)
        for row in reader:
            dnas.append(row)
        for col in range(1, reader.fieldnames.__len__()):
            strs.append(reader.fieldnames.__getitem__(col))

    with open(sys.argv[2], 'r', encoding="utf-8") as seq_file:
        seq = seq_file.read()

    values = []
    for _ in strs:
        values.append(longest_match(seq, _))

    found = False
    for dna in dnas:
        match_dna = True
        for _ in range(0, strs.__len__()):
            if int(dna[strs[_]]) != values[_]:
                match_dna = False
                break
        if match_dna == True:
            print(dna["name"])
            found = True
    if found == False:
        print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
