The idea is that we want to find the average processing time for each machine. 
To achieve this, we can use a self join on the Activity table and compare the timestamps of each record with the timestamps of the previous record.
We use matching machine_id and process_id to ensure that we are comparing the start and end times of the same process on the same machine.

select a1.machine_id, round(avg(a1.timestamp - a2.timestamp), 3) as processing_time
from Activity a1, Activity a2
where a1.machine_id = a2.machine_id and a1.process_id = a2.process_id and a1.activity_type = "end" and a2.activity_type = "start"
group by a1.machine_id;