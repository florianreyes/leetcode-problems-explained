-- The idea is to segments which can form a triangle


SELECT x,y,z,
CASE 
    WHEN ((x+y) > z) AND ((x+z) > y) AND ((y+z) > x) THEN 'Yes'
    ELSE 'No'
END AS triangle
FROM Triangle;