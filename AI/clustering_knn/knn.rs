use std::borrow::Borrow;
use std::collections::HashMap;
use std::mem;


fn main() {
    let mut vec = Vec::new();
    vec.push(1);
    vec.push(2);

    let vec2 = vec![3, 4, 5];

    let matrix = vec![vec![3,4,5], vec2];

    let classification_data = vec![
        vec![22, 1],
        vec![23, 1],
        vec![21, 1],
        vec![18, 1],
        vec![19, 1],
        vec![25, 0],
        vec![27, 0],
        vec![29, 0],
        vec![31, 0],
        vec![45, 0],
    ];

    knn(2, classification_data, vec![17, 0]);
}


fn knn(n: usize, instances: Vec<Vec<i32>>, query: Vec<i32>) {
    println!("I will perform query = {:?} knn with n={} and with {} instances", query, n, instances.len());

    let mut neigh_dist_and_indices = Vec::new();

    for i in (1..instances.len()).rev() {
        let distance = euclidean_distance(&query, instances.get(i).unwrap());
        neigh_dist_and_indices.push((distance, i));
    }

    println!("neighbors without sorting: {:?}", neigh_dist_and_indices);

    // Sort neigh_dist_and_indices
    neigh_dist_and_indices.sort_by(|a, b| a.0.partial_cmp(&b.0).unwrap());

    println!("neighbors sorted: {:?}", neigh_dist_and_indices);

    let mut k_nearest = &neigh_dist_and_indices[..n];

    println!("k neighbors: {:?}", k_nearest);

    let mut k_nearest_labels = Vec::new();

    for pair in k_nearest {
        let index:usize = pair.borrow().1;
        let label = *instances.get(index).unwrap().get(1).unwrap();
        k_nearest_labels.push(label);
    }

    println!("Result: {:?}", mode(&k_nearest_labels));
}

fn euclidean_distance(v1: &Vec<i32>, v2: &Vec<i32>) -> f64 {
    println!("Vector v1: {:?} and v2: {:?}", v1, v2);
    let mut distance_sq = 0.0;
    let mut i = 0;
    while i < v1.len() {
        let part:f64 = (v2.get(i).unwrap() - v1.get(i).unwrap()).into();
        distance_sq += part * part;
        i += 1;
    }
    return distance_sq.sqrt();
}

fn mode(numbers: &Vec<i32>) -> Vec<i32> {
    let mut map = HashMap::new();
    for integer in numbers {
        let count = map.entry(integer).or_insert(0);
        *count += 1;
    }

    let max_value = map.values().cloned().max().unwrap_or(0);

    map.into_iter()
        .filter(|&(_, v)| v == max_value)
        .map(|(&k, _)| k)
        .collect()
}