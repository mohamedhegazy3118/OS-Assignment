
sleep 300 &
PID=$!
echo "Started sleep process with PID: $PID"


ps aux | grep sleep


echo "Killing process $PID..."
kill $PID


echo "Verifying process is gone:"
ps aux | grep sleep
