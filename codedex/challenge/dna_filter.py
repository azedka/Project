dna_sequence = ['GCT', 'AGC', 'AGG', 'TAA', 'ACT', 'CAT', 'TAT', 'CCC', 'ACG', 'GAA', 'ACC', 'GGA']
test = "GGA"
result = False


for dna in dna_sequence:
    if dna == test:
        print("Item Found!")
        result = True
        break
    else:
        print("Item Not Found!")