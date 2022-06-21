/**
 * @param {number[]} heights
 * @param {number} bricks
 * @param {number} ladders
 * @return {number}
 */
var furthestBuilding = function(heights, bricks, ladders) {
    const n = heights.length
    let left = 0, right = n - 1
    const needs = Array(n).fill(0)
    
    for (let i = 1; i < n; i += 1) {
        needs[i] = Math.max(0, heights[i] - heights[i - 1])
    }
    
    const canReach = (index) => {
        if (ladders > index) return true
        const arr = needs.slice(0, index + 1).sort((a, b) => a - b)
        
        let needBricks = bricks
        let i = 0
        while (needBricks >= 0 & i < arr.length - ladders) {
            needBricks -= arr[i]
            i += 1
        }
        return needBricks >= 0
    }
    
    while (left < right) {
        const middle = Math.ceil((left + right) / 2)
        if (canReach(middle)) {
            left = middle
        } else {
            right = middle - 1
        }
    }
    
    return left;
};
    