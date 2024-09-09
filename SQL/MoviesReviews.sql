WITH user_rating_counts AS (
    SELECT 
        u.name, 
        COUNT(mr.movie_id) AS rating_count
    FROM 
        Users u
    JOIN 
        MovieRating mr ON u.user_id = mr.user_id
    GROUP BY 
        u.name
    ORDER BY 
        rating_count DESC, u.name ASC
    LIMIT 1
),
february_2020_movies AS (
    SELECT 
        m.title, 
        AVG(mr.rating) AS avg_rating
    FROM 
        Movies m
    JOIN 
        MovieRating mr ON m.movie_id = mr.movie_id
    WHERE 
        mr.created_at BETWEEN '2020-02-01' AND '2020-02-29'
    GROUP BY 
        m.title
    ORDER BY 
        avg_rating DESC, m.title ASC
    LIMIT 1
)
SELECT 
    u.name AS results
FROM 
    user_rating_counts u

UNION ALL

SELECT 
    f.title AS movie_name
FROM 
    february_2020_movies f;
