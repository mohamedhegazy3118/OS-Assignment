
sleep 300 &
PID=$!
echo "Started process with PID: $PID"


echo "Pausing process $PID..."
kill -STOP $PID




echo "Resuming process $PID..."
kill -CONT $PID

#
jobs


kill $PID
