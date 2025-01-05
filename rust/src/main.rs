fn do_binary_search(array: &Vec<i32>, array_size: usize, number_to_search: i32) -> Option<usize> {
    let mut lower_limit: usize;
    let mut upper_limit: usize;
    let mut middle: usize;

    if array_size == 0 {
        return None;
    }
    if array_size == 1 && array[0] == number_to_search {
        return Some(0);
    }
    lower_limit = 0;

    upper_limit = array_size - 1;
    while lower_limit <= upper_limit {
        middle = (lower_limit + upper_limit) / 2;
        if array[middle] == number_to_search {
            return Some(middle);
        }
        if (middle == 0 && number_to_search < array[middle])
            || (middle == array_size - 1 && number_to_search > array[middle])
        {
            break;
        } else if number_to_search < array[middle] {
            upper_limit = middle - 1;
        } else {
            lower_limit = middle + 1;
        }
    }
    None
}

fn main() {
    let sample_vector: Vec<i32> = vec![1, 2, 4, 6, 8, 10, 20, 30, 50, 80, 100];
    let size_vector: usize = sample_vector.len();
    if let Some(index) = do_binary_search(&sample_vector, size_vector, 80) {
        println!("The element 80 was found in index {}", index);
    } else {
        eprintln!("Element 80 not found");
    }
    if let Some(index) = do_binary_search(&sample_vector, size_vector, 2) {
        println!("The element 2 was found in index {}", index);
    } else {
        eprintln!("Element 2 not found");
    }
    if let Some(index) = do_binary_search(&sample_vector, size_vector, 1) {
        println!("The element 1 was found in index {}", index);
    } else {
        eprintln!("Element 1 not found");
    }
    if let Some(index) = do_binary_search(&sample_vector, size_vector, 100) {
        println!("The element 100 was found in index {}", index);
    } else {
        eprintln!("Element 100 not found");
    }
    if let Some(index) = do_binary_search(&sample_vector, size_vector, 200) {
        println!("The element 200 was found in index {}", index);
    } else {
        eprintln!("Element 200 not found");
    }
}
