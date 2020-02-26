./generator --big-superposition > map
echo "smight:\c"
echo "$(./smight_lem-in < bs1 | grep L | wc -l)"
echo "dbennie\c"
echo "$(./lem-in < bs1 | grep L | wc -l)"

rm -rf map
