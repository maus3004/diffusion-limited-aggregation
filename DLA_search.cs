using System.Collections;
using UnityEngine;

public class DLA_search : MonoBehaviour
{
    Mesh mesh;
    Vector3[] vertices;

    public int x_size = 10;
    public int z_size = 10;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        mesh = new Mesh();
        GetComponent<MeshFilter>().mesh = mesh;

        CreateShape();
        UpdateShape();
        StartCoroutine(walk());
    }

    void CreateShape()
    {
        
    }

    void UpdateShape() {
        
    }

    bool check()
    {
        return true;
    }

    IEnumerator walk()
    {
        
        yield return new WaitForSeconds(0.2f);
    }
    // create a board, or a mesh of vertices. 
    // need a check function that returns true or false
    // need a walking function
    // let's have it fill the board first and then we can try to limit it

    // Update is called once per frame
    void Update()
    {
        
    }
}
