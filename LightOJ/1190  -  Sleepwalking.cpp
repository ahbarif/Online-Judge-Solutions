#include <bits/stdc++.h>
using namespace std;
 
struct Point
{
    int x, y;
    Point(){}
} a[1005];
 
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&  q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    else return false;
}
 
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}
 
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
 
    if (o1 != o2 && o3 != o4)      return true;
 
 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false;
}
 
 
bool isInside(Point polygon[], int n, Point p)
{
    if (n < 3)  return false;
 
    Point extreme;
 
    extreme.x = p.x + 20001;
    extreme.y = p.y + 20002;
 
    int count = 0, i = 0;
 
    do
    {
        int next = (i+1)%n;
 
        if (doIntersect(polygon[i], polygon[next], p, extreme))
        {
 
            if (orientation(polygon[i], p, polygon[next]) == 0)
                return onSegment(polygon[i], p, polygon[next]);
 
            count++;
        }
        i = next;
    }  while (i != 0);
 
    return count&1;
}
 
int main()
{
 
    int test, cs = 0;
 
    scanf("%d", &test);
 
    while(test--)
    {
 
        int n, i, query;
 
        scanf("%d", &n);
 
        for(i=0; i<n; i++)  scanf("%d %d", &a[i].x, &a[i].y);
 
        scanf("%d", &query);
 
        printf("Case %d:\n", ++cs);
 
        while(query--)
        {
            Point q;
 
            scanf("%d %d", &q.x, &q.y);
 
            if(isInside(a, n, q))  puts("Yes");
 
            else puts("No");
        }
    }
 
    return 0;
}