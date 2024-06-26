-- The idea is that we want to find the weather records where the temperature is higher than the previous day.
-- To achieve this, we can use a self join on the Weather table and compare the temperature of each record with the temperature of the previous day.

select w1.id
from Weather w1, Weather w2
where DATEDIFF(w1.recordDate, w2.recordDate) = 1 and w1.temperature > w2.temperature;