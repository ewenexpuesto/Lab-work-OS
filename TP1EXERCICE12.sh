# QUESTION 1
find /pub/FISE_OSSE11/shell/projet -type f -name '*.[ch]' | wc -l

# QUESTION 2
find /pub/FISE_OSSE11/shell/projet -type f -name '*\.[ch]' -exec cat {} \; | wc -l

# QUESTION 3
find /pub/FISE_OSSE11/shell/projet -type f -name '*\.[ch]' -exec grep atoi {} \;

# QUESTION 4
# a
find ~/tmp/projet -name '*\.[ch]' -exec echo "cp {} {}.orig" \;

# b
find ~/tmp/projet -name '*\.[ch]' | wc -l
find ~/tmp/projet -name '*\.orig' | wc -l

if [ $(find ~/tmp/projet -name '*\.[ch]' | wc -l) -eq $(find ~/tmp/projet -name '*\.orig' | wc -l) ]; then echo "OK"; elso echo "KO" ; fi

# c
find ~/tmp/projet -name '*\.[ch]' -exec sed -i -e 's/dupont/Dupont/g' -e 's/jean/Jean/g' {} \;

find ~/tmp/projet -name '*\.[ch]' -exec grep -w -l -e jean -e  dupont {} \;

find ~/tmp/projet -name '*\.[ch]' -exec grep Jean {} \;

find ~/tmp/projet -name '*\.[ch]' -exec grep -q Jean {} \;

find ~/tmp/projet -name '*\.[ch]' -exec grep -l Jean {} \;

find ~/tmp/projet -name '*\.[ch]' -exec grep -q Jean {} \; -print

find ~/tmp/projet -name '*\.[ch]' -exec grep -q Jean {} \; -exec cp -v {}.orig{} \;

# avec le -i, pas de retour possible

# QUESTION 5
