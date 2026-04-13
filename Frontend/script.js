// Graph datasets
var nodes = new vis.DataSet();
var edges = new vis.DataSet();

var container = document.getElementById("network");

var data = {
  nodes: nodes,
  edges: edges,
};

// Graph appearance options
var options = {
  nodes: {
    shape: "dot",
    size: 30,
    font: {
      size: 20,
      color: "white",
      face: "arial",
    },
  },

  edges: {
    width: 3,
    smooth: true,
    font: {
      size: 18,
      align: "top",
      color: "black",
    },
  },

  physics: {
    stabilization: false,
  },
};

var network = new vis.Network(container, data, options);

// Convert edge input into JSON
function getEdgesFromInput() {
  let edgesText = document.getElementById("edges").value.split("\n");

  let edgeList = [];

  edgesText.forEach((line) => {
    let parts = line.trim().split(" ");

    if (parts.length === 3) {
      edgeList.push({
        u: parseInt(parts[0]),
        v: parseInt(parts[1]),
        w: parseInt(parts[2]),
      });
    }
  });

  return edgeList;
}

// Build graph dynamically
function buildGraphFromInput() {
  let nodesCount = parseInt(document.getElementById("nodes").value);
  let source = parseInt(document.getElementById("source").value);
  let destination = parseInt(document.getElementById("destination").value);

  let edgesText = document.getElementById("edges").value.split("\n");

  nodes.clear();
  edges.clear();

  // Create nodes
  for (let i = 0; i < nodesCount; i++) {
    let color = "#3498db";

    if (i === source) color = "#00e35f"; // Source = green
    if (i === destination) color = "#a71808"; // Destination = red

    nodes.add({
      id: i,
      label: i.toString(),
      color: color,
    });
  }

  // Create edges
  let id = 1;

  edgesText.forEach((line) => {
    let p = line.trim().split(" ");

    if (p.length === 3) {
      edges.add({
        id: id++,
        from: parseInt(p[0]),
        to: parseInt(p[1]),
        label: p[2],
        color: { color: "#d1ef0e" },
      });
    }
  });
}

// Send request to backend
function sendAlgo(algo) {
  buildGraphFromInput();

  let nodesCount = parseInt(document.getElementById("nodes").value);
  let source = parseInt(document.getElementById("source").value);
  let destination = parseInt(document.getElementById("destination").value);

  let edgeList = getEdgesFromInput();

  fetch(`http://localhost:18080/${algo}`, {
    method: "POST",

    headers: {
      "Content-Type": "application/json",
    },

    body: JSON.stringify({
      nodes: nodesCount,
      edges: edgeList,
      source: source,
      destination: destination,
    }),
  })
    .then((res) => res.json())
    .then((data) => {
      let path = data.path;
      let distance = data.distance;

      // Show result
      document.getElementById("result").innerText =
        `Shortest Path: ${path.join(" → ")} | Distance: ${distance}`;

      highlightPath(path);
    })
    .catch((err) => {
      console.error("Error:", err);
    });
}

// Algorithm buttons
function runDijkstra() {
  sendAlgo("dijkstra");
}

function runBellman() {
  sendAlgo("bellmanford");
}

function runFloyd() {
  sendAlgo("floydwarshall");
}

// Highlight shortest path
function highlightPath(path) {
  resetGraph();

  // Highlight edges
  for (let i = 0; i < path.length - 1; i++) {
    edges.forEach(function (edge) {
      if (
        (edge.from === path[i] && edge.to === path[i + 1]) ||
        (edge.from === path[i + 1] && edge.to === path[i])
      ) {
        edges.update({
          id: edge.id,
          color: { color: "#ff0000" },
          width: 6,
        });
      }
    });
  }

  // Highlight nodes
  nodes.update(
    path.map((node) => ({
      id: node,
      color: "#ff0000",
    })),
  );
}

// Reset graph edges & nodes
function resetGraph() {
  edges.forEach(function (edge) {
    edges.update({
      id: edge.id,
      color: { color: "#d4a818" },
      width: 3,
    });
  });

  nodes.forEach(function (node) {
    nodes.update({
      id: node.id,
      color: "#3498db",
    });
  });
}
